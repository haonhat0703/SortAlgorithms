// COUNTINGSORT *********************************

#include <iostream>
#include <math.h>

using namespace std;

const int N = int(1e4);// hang so ve so phan tu toi da cua mang

void input(int a[], int& n);// Ham nhap mang voi so phan tu la n
void CountingSort(int a[], int n);// Ham sap xep dem phan phoi
void output(int a[], int n);// Ham xuat mang sau khi sap xep

int main()
{
	int a[N], n;
	input(a, n);
	CountingSort(a, n);
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

void CountingSort(int a[], int n) {
	int tmp[N];
	int minn = a[0], maxx = a[0];

	for (int i = 1; i < n; i++)// tim min max cua cac phan tu trong mang
		minn = min(minn, a[i]), maxx = max(maxx, a[i]);

	int k = maxx - minn + 1;// khoang gia tri trai dai tu 0 den k - 1

	int cnt[N];
	for (int i = 0; i < k; i++) 
			cnt[i] = 0;// khoi tao gia tri dem phan phoi trong khoang = 0

	for (int i = 0; i < n; i++) 
			cnt[a[i] - minn]++;// thuc hien viec den phan phoi so luong phan tu bang cach quy ve khoang 0 den k - 1

	for (int i = 1; i < k; i++)
			cnt[i] += cnt[i - 1];// cong don mang

	for (int i = 0; i < n; i++)
			tmp[--cnt[a[i] - minn]] = a[i];// xac dinh lai vi tri chinh xac, co the chay tu n - 1 den 0 de dam bao tinh on dinh cua thuat toan sx 
	 
	for (int i = 0; i < n; i++)
		a[i] = tmp[i];// cap nhap mang sau khi sap xep cho mang chinh 
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}