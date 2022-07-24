//{}[]

// HEAPSORT *********************************

#include <iostream>

using namespace std;

const int N = int(1e5);// hang so ve so phan tu toi da cua mang

void swap(int& a, int& b);// ham doi cho hai phan tu
void input(int a[], int& n);// Ham nhap mang voi so phan tu la n
void heapify(int a[], int n, int i);// de quy vun dong
void HeapSort(int a[], int n);// Ham sap xep vun dong
void output(int a[], int n);// Ham xuat mang sau khi sap xep

int main()
{
	int a[N], n;
	input(a, n);
	HeapSort(a, n);
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

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void heapify(int a[], int n, int i) {
	int max = i, l = i*2 + 1, r = i*2 + 2;// khoi tao vt max, nut trai va nut phai cua node hien tai dang kiem tra
	if (l < n && a[l] > a[max]) max = l;// tim vi tri max
	if (r < n && a[r] > a[max]) max = r;// tim vi tri max
	if (max != i) {
		swap(a[i], a[max]);// doi cho phan tu lon nhat
		heapify(a, n, max);// vun lai dong phia duoi
	} 
}

void HeapSort(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);// vun lai tung dinh

	for (int i = n - 1; i > 0; i--) {// loai bo lan luot cac phan tu cuoi ra khoi heap
		swap(a[0], a[i]);// doi vi tri phan tu max ve cuoi
		heapify(a, i, 0);// vun lai dong 
	} 
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}