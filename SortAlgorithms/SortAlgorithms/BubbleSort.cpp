// BUBBLESORT *********************************

#include <iostream>

using namespace std;

const int N = int (1e5);// hang so ve so phan tu toi da cua mang

void input(int a[], int& n);// Ham nhap mang voi so phan tu la n
void BubbleSort(int a[], int n);// Ham sap xep noi bot
void output(int a[], int n);// Ham xuat mang sau khi sap xep

int main() 
{
	int a [N] , n;
	input(a, n);// nhap
	BubbleSort(a, n);// sort
	output(a, n);// output
	return 0;
}

void input(int a[], int& n) {
	cout << "Nhap so phan tu cua mang can sap xep: ";
	cin >> n;

	for (int i = 0; i < n; i++) {// nhap mang n phan tu
		cout << "Nhap phan tu a [" << i << "] = ";
		cin >> a[i];
	}
}

void BubbleSort(int a[], int n) {
	for (int i = 1; i < n; i++)
		for (int j = n - 1; j >= i; j--)// chay tu cuoi len nhu noi bot
			if (a[j - 1] > a[j]) // dieu kien sap xep tang dan 
			{// Swap vi tri neu khong dung thu tu mong muon
				int tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)// xuat mang
		cout << a[i] << " ";
}