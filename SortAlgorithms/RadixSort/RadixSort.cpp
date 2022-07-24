// RADIXSORT *********************************

#include <iostream>
#include <math.h>

using namespace std;

const int N = int(1e5);// hang so ve so phan tu toi da cua mang

void input(int a[], int& n);// Ham nhap mang voi so phan tu la n
void countingSort(int a[], int n, int div);// sort bang dem phan phoi
void RadixSort(int a[], int n);// Ham sap xep radixSort
void output(int a[], int n);// Ham xuat mang sau khi sap xep

int main()
{
	int a[N], n;
	input(a, n);
	RadixSort(a, n);
	output(a, n);
	return 0;
}

void input(int a[], int& n) {
	cout << "Nhap so phan tu cua mang can sap xep: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu a [" << i << "] = ";
		cin >> a[i];
	}
}

void countingSort(int a[], int n, int div) {
	int countingKeys[10] = {0};
	int* res = new int[n];
	int key;

	for (int i = 0; i < n; i++) {
		key = (a[i] / div) % 10;
		countingKeys[key]++;
	} 

	for (int i = 1; i < 10; i++)
		countingKeys[i] += countingKeys[i - 1];

	for (int i = n - 1; i >= 0; i--) {// chay tu cuoi len de dat duoc su on dinh cua thuat toan sap xep
		key = (a[i] / div) % 10;
		res[--countingKeys[key]] = a[i];
	} 

	for (int i = 0; i < n; i++)
		a[i] = res[i];

	delete[] res;
}

void RadixSort(int a[], int n) {
	int maxx = a[0];
	for (int i = 1; i < n; i++) 
		maxx = max(a[i], maxx);

	for (int divisionUnit = 1; divisionUnit <= maxx; divisionUnit *= 10)// chay co so
		countingSort(a, n, divisionUnit);// sort theo co so
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}