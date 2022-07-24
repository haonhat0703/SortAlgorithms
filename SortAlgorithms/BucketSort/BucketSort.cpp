
// chi sap xep duoc trong khoang nho nhat dinh
// bai nay khoang gia tri tu 0 den 1 

// BUCKETSORT *********************************

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back// define lenh push_back

const int N = int(1e4);// hang so ve so phan tu toi da cua mang

void input(double a[], int& n);// Ham nhap mang voi so phan tu la n
void BucketSort(double a[], int n);// Ham sap xep bucket
void output(double a[], int n);// Ham xuat mang sau khi sap xep

int main()
{
	int n;
	double a[N];
	input(a, n);
	BucketSort(a, n);
	output(a, n);
	return 0;
}

void input(double a[], int& n) {
	cout << "Nhap so phan tu cua mang can sap xep: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu a [" << i << "] = ";
		cin >> a[i];
	}
}

void BucketSort(double a[], int n) {
	
	//1) Create empty buckets 
	vector<double> b[N];

	//2) Put array elements in different buckets
	for (int i = 0; i < n; i++) {
		int bi = int (a[i] * n);// Index in bucket
		b[bi].pb(a[i]);
	} 

	//3) Sort individual buckets
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());// goi ham sap xep co san trong thu vien <(^-^)>

	//4) Concatenate all buckets into arr
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			a[index++] = b[i][j];
}

void output(double a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}