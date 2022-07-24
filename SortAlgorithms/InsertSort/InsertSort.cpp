// INSERTSORT *********************************

#include <iostream>

using namespace std;

const int N = int(1e5);// hang so ve so phan tu toi da cua mang

void input(int a[], int& n);// Ham nhap mang voi so phan tu la n
void InsertSort(int a[], int n);// Ham sap xep chen
void InsertSortWithBinarySearch(int a[], int n); // Ham sap xep chen bang cach  ket hop voi tim nhi phan
void output(int a[], int n);// Ham xuat mang sau khi sap xep

int main()
{
	int a[N], n;
	input(a, n);
	//InsertSort(a, n);
	InsertSortWithBinarySearch(a, n);
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

void InsertSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int tmp = a[i], j = i - 1;
		while (j >= 0 && tmp < a[j])
			a[j + 1] = a[j--];
		a[j + 1] = tmp;
	} 
}

void InsertSortWithBinarySearch(int a [], int n) {
	for (int i = 1; i < n; i++) {
		int tmp = a[i], l = 0, r = i - 1;
		
		while (l <= r)// ket hop chat nhi phan tim vi tri thoa trong khoang phia truoc vi da sap xep khoang nay
		{
			int mid = (l + r) / 2;
			if (tmp < a[mid]) r = mid - 1;
			else l = mid + 1;
		}

		for (int j = i; j > l; j--) 
				a[j] = a[j - 1];
		a[l] = tmp;
	} 
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}