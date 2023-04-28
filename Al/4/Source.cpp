#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
void PrintMas(int** mas, int numStr, int numCol) {
	for (int i = 0; i < numStr; i++) {
		for (int j = 0; j < numCol; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}

void SwapMas(int** mas, int i, int j, int numCol) {
	int* temp = new int[numCol];
	memcpy(&temp[0], &mas[i][0], numCol);
	memcpy(&mas[i][0], &mas[j][0], numCol);
	memcpy(&mas[j][0], &temp[0], numCol);
}
int Har(int* mas, int masSize) {
	int sum = 0;
	for (int i = 0; i < masSize; i++) {
		if ((mas[i] > 0) && ((mas[i] % 2) == 0))
			sum += mas[i];
	}
	return sum;
}
int Partinion(int** mas, int* har, int p, int q, int numCol) {
	int i = p;
	int j = q;
	int t; //рабоча€ переменна€
	while (1) {
		while ((har[p] >= har[i]) && (i < q)) {
			i++;
		}
		while ((har[p] <= har[j]) && (j > p + 1)) {
			j--;
		}
		if (i < j) {
			SwapMas(mas, i, j, numCol);
			t = har[j];
			har[j] = har[i];
			har[i] = t;
		}
		else {
			if (har[j] < har[p]) {
				SwapMas(mas, p, j, numCol);
				t = har[j];
				har[j] = har[p];
				har[p] = t;
			}
			return j;
		}
	}
}
void QuickSort(int** mas, int* har, int p, int r, int numCol) {
	int q; //рабоча€ переменна€
	if (p < r) {
		q = Partinion(mas, har, p, r, numCol);
		if (p < q) {
			QuickSort(mas, har, p, q - 1, numCol);
			QuickSort(mas, har, q, r, numCol);
		}
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "¬ведите количество строк массива:  ";
	cin >> n;
	int m;
	cout << "¬ведите количество столбцов массива:  ";
	cin >> m;
	cout << endl;
	int** mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cout << "¬ведите " << j << "-ый элемент " << i << "-ой строки массива: ";
			cin >> mas[i][j];
			cout << endl;
		}
	}
	cout << "¬ведЄнный массив" << endl;
	PrintMas(mas, n, m);
	cout << endl;
	int numColWithoutOne = 0;
	int count = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (mas[i][j] == 0)
				count++;
		}
		if (count > 0)
			numColWithoutOne++;
		count = 0;
	}
	cout << " оличество ненулевых столбцов:  " << (m - numColWithoutOne) << endl;
	int* har = new int[n];
	for (int j = 0; j < n; j++) {
		har[j] = Har(mas[j], m);
	}
	QuickSort(mas, har, 0, n - 1, m);
	cout << "Ёлементы массива после сортировки: \n";
	PrintMas(mas, n, m);
	cout << endl;
	for (int i = 0; i < n; i++) {
		delete[] mas[i];
	}
	delete[] mas;
	delete[] har;
	_getch();
}
