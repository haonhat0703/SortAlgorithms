// QUICKSORT *********************************

#include <iostream>

using namespace std;

const int N = int(1e5);// hang so ve so phan tu toi da cua mang

void input(int a[], int& n);// Ham nhap mang voi so phan tu la n
void QuickSort(int a[], int left, int right);// Ham sap xep nhanh (phan hoach)
void output(int a[], int n);// Ham xuat mang sau khi sap xep

int main()
{
	int a[N], n;
	input(a, n);
	QuickSort(a, 0, n - 1);
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

void QuickSort(int a[], int left, int right) {
	int i = left, j = right, x = a[(left + right) / 2];
	while (i < j) {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (!(i>j)) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++, j--;
		}
	} 
	if (i < right) QuickSort(a, i, right);
	if (left < j) QuickSort(a, left, j);
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}