// SHELLSORT *********************************

#include <iostream>

using namespace std;

const int N = int(1e5);// hang so ve so phan tu toi da cua mang

void input(int a[], int& n);// Ham nhap mang voi so phan tu la n
void ShellSort(int a[], int n);// Ham sap xep shell sort
void output(int a[], int n);// Ham xuat mang sau khi sap xep

int main()
{
	int a[N], n;
	input(a, n);
	ShellSort(a, n);
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

void ShellSort(int a[], int n) {
	int j, interval = 1;// buoc nhay
	
	while (interval <= (n / 3)) 
			interval = interval * 3 + 1;// toi uu cua buoc nhay nhat co the

	while (interval > 0)
	{
		for (int i = interval; i < n; i++) {// su dung chen truc tiep de dam bao su on dinh cua thuat toan
			int comp = a[i];
			for (j = i; j >= interval && a[j - interval] > comp; j -= interval)
				a[j] = a[j - interval];
			a[j] = comp;
		}
		interval = (interval - 1) / 3;
	}
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}