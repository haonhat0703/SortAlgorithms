// SELECTSORT *********************************

#include <iostream>

using namespace std;

const int N = int(1e5);// hang so ve so phan tu toi da cua mang

void input(int a[], int& n);// Ham nhap mang voi so phan tu la n
void SelectSort(int a[], int n);// Ham sap xep chon
void output(int a[], int n);// Ham xuat mang sau khi sap xep

int main()
{
	int a[N], n;
	input(a, n);
	SelectSort(a, n);
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

void SelectSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)// tim vi tri gia tri nho nhat trong khoang sau
			if (a[j] < a[minIndex])
				minIndex = j;

		int tmp = a[i];// dua gia tri nho nhat trong khoang sau ve dau
		a[i] = a[minIndex];
		a[minIndex] = tmp;
	} 
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}