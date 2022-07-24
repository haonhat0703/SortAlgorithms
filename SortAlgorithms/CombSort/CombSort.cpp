// COMPSORT *********************************

#include <iostream>

using namespace std;

const int N = int(1e5);// hang so ve so phan tu toi da cua mang

int getNextGap(int gap);// khoang nhay trong lan sap xep
void input(int a[], int& n);// Ham nhap mang voi so phan tu la n
void CompSort(int a[], int n);// Ham sap xep comp
void output(int a[], int n);// Ham xuat mang sau khi sap xep

int main()
{
	int a[N], n;
	input(a, n);
	CompSort(a, n);
	output(a, n);
	return 0;
}

int getNextGap(int gap) {
	gap = gap * 10 / 13;
	if (gap < 1)
			return 1;
	return gap;
}

void input(int a[], int& n) {
	cout << "Nhap so phan tu cua mang can sap xep: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu a [" << i << "] = ";
		cin >> a[i];
	}
}

void CompSort(int a[], int n) {
	int gap = n;
	bool swapped = true;

	while (gap != 1 || swapped) {
		gap = getNextGap(gap);
		swapped = false;

		for (int i = 0; i < n - gap; i++)
			if (a [i] > a[i + gap])
			{// doi cho va danh dau da thuc hien swap
				int tmp = a[i];
				a[i] = a[i + gap];
				a[i + gap] = tmp;
				swapped = true;
			}
	} 
	 
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}