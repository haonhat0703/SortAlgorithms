// MERGESORT *********************************

#include <iostream>

using namespace std;

const int N = int(1e5);// hang so ve so phan tu toi da cua mang

void input(int a[], int& n);// Ham nhap mang voi so phan tu la n
void merge(int a[], int left, int middle, int right);// Ham noi hai mang lai
void MergeSort(int a[], int left, int right);// Ham sap xep merge 
void output(int a[], int n);// Ham xuat mang sau khi sap xep

int main()
{
	int a[N], n;
	input(a, n);
	MergeSort(a, 0, n - 1);
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

void merge (int a[], int left, int middle, int right)
{
	int leftSize = middle - left + 1;
	int	rightSize = right - middle;

	int* L = new int[leftSize];
	int* R = new int[rightSize];

	for (int i = 0; i < leftSize; i++) L[i] = a[i + left];
	for (int i = 0; i < rightSize; i++) R[i] = a[i + middle + 1];

	int i = 0, j = 0, k = left;
	while (i < leftSize && j < rightSize)
		a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];

	while (i < leftSize)
		a[k++] = L[i++];
	while (j < rightSize)
		a[k++] = R[j++];

	delete[] L;
	delete[] R;
}

void MergeSort(int a[], int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		MergeSort(a, left, middle);
		MergeSort(a, middle + 1, right);
		merge(a, left, middle, right);
	}
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}