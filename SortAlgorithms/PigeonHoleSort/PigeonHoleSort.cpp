// PIGEONHOLESORT *********************************

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const int N = int(1e4);// hang so ve so phan tu toi da cua mang

void input(int a[], int& n);// Ham nhap mang voi so phan tu la n
void PigeonHoleSort(int a[], int n);// Ham sap xep nhot chim vao long
void output(int a[], int n);// Ham xuat mang sau khi sap xep

int main()
{
	int a[N], n;
	input(a, n);
	PigeonHoleSort(a, n);
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

void PigeonHoleSort(int a[], int n) {
	int maxx = a[0], minn = a[0];
	for (int i = 1; i < n; i++) 
		maxx = max(a[i], maxx), minn = min(a[i], minn);

	int range = maxx - minn + 1;
	vector<int> *holes = new vector<int> [range];

	for (int i = 0; i < n; i++)
		holes[a[i] - minn].push_back(a[i]);
	
	int index = 0;

	for (int i = 0; i < range; i++)
		for (int j = 0; j < holes[i].size(); j++)
			a[index++] = holes[i][j];

	delete[] holes;
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}