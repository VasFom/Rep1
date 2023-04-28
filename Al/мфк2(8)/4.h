#pragma once
#pragma once
#include <iostream>
using namespace std;

template <typename T>
void PrintMas(T** mas, int numStr, int numCol) {
	for (int i = 0; i < numStr; i++) {
		for (int j = 0; j < numCol; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}

template <typename T>
void CopyMas(T* mas1, T* mas2, int masSize) {
	for (int i = 0; i < masSize; i++) {
		mas1[i] = mas2[i];
	}
}

template <typename T>
void SwapMas(T** mas, int i, int j, int numCol) {
	T* temp = new T[numCol];
	CopyMas(temp, mas[i], numCol);
	CopyMas(mas[i], mas[j], numCol);
	CopyMas(mas[j], temp, numCol);
	delete temp;
}

template <typename T>
int Har(T* mas, int masSize) {
	int sum = 0;
	for (int i = 0; i < masSize; i++) {
		if ((mas[i] > 0) && (((int)mas[i] % 2) == 0))
			sum += mas[i];
	}
	return sum;
}

template <typename T>
int Partinion2(T** mas, int* har, int p, int q, int numCol) {
	int i = p;
	int j = q;
	int t; //рабочая переменная
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
template <typename T>
void QuickSort(T** mas, int* har, int p, int r, int numCol) {
	int q; //рабочая переменная
	if (p < r) {
		q = Partinion2(mas, har, p, r, numCol);
		if (p < q) {
			QuickSort(mas, har, p, q - 1, numCol);
			QuickSort(mas, har, q, r, numCol);
		}
	}
}
template <typename T>
int CountNoNullCol(T** mas, int numStr, int numCol) {
	int numColWithoutOne = 0;
	int count = 0;
	for (int j = 0; j < numCol; j++) {
		for (int i = 0; i < numStr; i++) {
			if (mas[i][j] == 0)
				count++;
		}
		if (count > 0)
			numColWithoutOne++;
		count = 0;
	}
	return (numCol - numColWithoutOne);
}
template <typename T>
void SortByHar(T** mas, int numStr, int numCol) {
	int* har = new int[numStr];
	for (int j = 0; j < numStr; j++) {
		har[j] = Har(mas[j], numCol);
	}
	QuickSort(mas, har, 0, numStr - 1, numCol);
	delete[] har;
}

