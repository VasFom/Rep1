#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int Partinion(float *mas, int p, int q) {
	int i = p;
	int j = q;
	float t; //������� ����������
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

void QuickSort(float *mas, int p, int r) {
	int q; //������� ����������
	if (p < r) {
		q = Partinion(mas, p, r);
		if (p < q) {
			QuickSort(mas, p, q - 1);
			QuickSort(mas, q, r);
		}
	}

}

void main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "������� ���������� ��������� �������:  ";
	cin >> n;
	cout << endl;
	float *mas = new float [n];
	for (int i = 0; i < n; i++) {
		cout << "������� " << i << "-�� ������� �������: ";
		cin >> mas[i];
	}

	float sum = 0;
	for (int j = 0; j < n; j++) {
		if (mas[j] > 0)
			sum += mas[j];
	}

	cout << "����� ������������� �������� �������:  " << sum << endl;
	
	int max, min;
	max = min = 0;
	for (int t = 1; t < n; t++) {
		if (abs(mas[t]) > abs(mas[max])) {
			max = t;
		} 

		if (abs(mas[t]) < abs(mas[min])) {
			min = t;
		}
	}

	int temp;

	if (max == min + 1) {
		cout << "����� ����������� � ������������ ���������� ������� ��������� ���" << endl;
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
		cout << "������������ ��������� �������, ��������������� ����� ����������� � ������������ ����������:  " << mult << endl;
	}

	QuickSort(mas, 0, n - 1);

	cout << "�������� ������� ����� ����������: ";
	for (int p = 0; p < n; p++) {
		cout << mas[p] << "  ";
	}

	delete [] mas;
}