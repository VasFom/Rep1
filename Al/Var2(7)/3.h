#pragma once

#include <iostream>

using namespace std;

void PrintMas(float* mas, int masSize) {
	for (int i = 0; i < masSize; i++) {
			cout << mas[i] << " ";
	}
	cout << endl;
}

int Partinion(float* mas, int p, int q) {
	int i = p;
	int j = q;
	float t; //рабочая переменная
	while (1) {

		while ((mas[p] <= mas[i]) && (i < q)) {
			i++;
		}

		while ((mas[p] >= mas[j]) && (j > p + 1)) {
			j--;
		}
		if (i < j) {
			t = mas[j];
			mas[j] = mas[i];
			mas[i] = t;
		}
		else {
			if (mas[j] > mas[p]) {
				t = mas[j];
				mas[j] = mas[p];
				mas[p] = t;
			}
			return j;
		}
	}
}

void QuickSort(float* mas, int p, int r) {
	int q; //рабочая переменная
	if (p < r) {
		q = Partinion(mas, p, r);
		if (p < q) {
			QuickSort(mas, p, q - 1);
			QuickSort(mas, q, r);
		}
	}

}

float SumPositiveElem(float *mas, int masSize) {
	float sum = 0;
	for (int j = 0; j < masSize; j++) {
		if (mas[j] > 0)
			sum += mas[j];
	}
	return sum;
}

float MultElemBetween(float* mas, int masSize) {
	int max, min;
	max = min = 0;
	for (int t = 1; t < masSize; t++) {
		if (abs(mas[t]) > abs(mas[max])) {
			max = t;
		}

		if (abs(mas[t]) < abs(mas[min])) {
			min = t;
		}
	}

	int temp;

	if (max == min + 1) {
		cout << "Между минимальным и максимальным элементами массива элементов нет";
		return 0.0;
	}
	else {
		if (min > max) {
			temp = max;
			max = min;
			min = temp;
		}

		float mult = 1;
		for (int k = min + 1; k < max; k++) {
			mult *= mas[k];
		}
		return mult;
	}
}

