#include <iostream>
#include <iomanip>
#include <time.h>
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Print2(int* b, const int k);
void Math1(int** a, int* b, const int k, const int n);
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo);
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 10;
	int n;
	int k;
	int z = 0;
	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;
	int** a = (int**) new int[k][5];
	int* b = new int[k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	CreateRows(a, k, n, Low, High, 0);
	for (int i = 0; i < k; i++) {
		for (int j = 0;j < n;j++) {
			if (a[i][j] < 0) {
				z = z - a[i][j];
			}
		}
		b[i] = z;
		z = 0;
	}
	Print(a, k, n, 0, 0);
	Print2(b, k);
	Math1(a, b, k, n);
	Print2(b, k);
	Print(a, k, n, 0, 0);
	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	delete[] b;
	return 0;
}
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo)

{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);

}
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo)

{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);

}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;

}
void Print2(int* b, const int k)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		cout << b[i];
		cout << endl;
	}
	cout << endl;
}
void Math1(int** a, int* b, const int k, const int n) {
	int tmp;
	for (int i = 0;i < k;i++) {
		for (int j = 0;j < k;j++) {
			for (int z = 0;z < n;z++) {
				if (b[i] > b[j]) {
					tmp = b[i];
					b[i] = b[j];
					b[j] = tmp;

					tmp = a[i][z];
					a[i][z] = a[j][z];
					a[j][z] = tmp;
				}
			}
		}
	}
}