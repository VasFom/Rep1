#include "3.h"
#include "4.h"
#include "5.h"
#include "6.h"

void main() {
	setlocale(LC_ALL, "rus");
	system("chcp 1251 > NULL");
	/////////////////////////////������� 3////////////////////
	cout << "������� 3" << endl;
	int n;
	cout << "������� ���������� ��������� �������:  ";
	cin >> n;
	cout << endl;
	float* mas = new float[n];
	for (int i = 0; i < n; i++) {
		cout << "������� " << i << "-�� ������� �������: ";
		cin >> mas[i];
	}

	cout << "����� ������������� �������� �������:  " << SumPositiveElem(mas, n) << endl;

	cout << "������������ ��������� �������, ��������������� ����� ����������� � ������������ ����������:  " << MultElemBetween(mas, n)<< endl;
	
	QuickSort(mas, 0, n - 1);

	cout << "�������� ������� ����� ����������: ";
	PrintMas(mas, n);

	delete[] mas;
	/////////////////////////////������� 4////////////////////
	cout << "������� 4" << endl;
	cout << "������� ���������� ����� �������:  ";
	cin >> n;

	int m;
	cout << "������� ���������� �������� �������:  ";
	cin >> m;
	cout << endl;

	int** mas2 = new int* [n];
	for (int i = 0; i < n; i++) {
		mas2[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cout << "������� " << j << "-�� ������� " << i << "-�� ������ �������: ";
			cin >> mas2[i][j];
			//cout << endl;
		}
	}
	cout << "�������� ������" << endl;
	PrintMas(mas2, n, m);
	cout << endl;

	cout << "���������� ��������� ��������:  " << CountNoNullCol(mas2, n, m) << endl;
	SortByHar(mas2, n, m);
	cout << "�������� ������� ����� ����������: \n";
	PrintMas(mas2, n, m);

	for (int i = 0; i < n; i++) {
		delete[] mas2[i];
	}
	delete[] mas2;

	/////////////////////////////������� 5////////////////////
	cout << "������� 5" << endl;
	string filename;
	cout << "������� �������� ����� ��� ���������:" << endl;
	cin >> filename;

	ifstream inputFile(filename, ios::binary);
	string text;
	inputFile.seekg(0, fstream::end);
	int sizeFile = inputFile.tellg();
	inputFile.seekg(0, fstream::beg);
	text.resize(sizeFile);
	inputFile.read(&text[0], sizeFile);

	cout << "�������� �����:" << endl;
	cout << text << endl;

	string word = "������";//�����, ������� ����
	cout << "������� �������� �����:  ";
	cin >> word;
	cout << word << endl;
	TextProcess(text, sizeFile, word);
	inputFile.close();
	/////////////////////////////������� 6////////////////////
	cout << "������� 6" << endl;
	int numStudent;
	cout << "������� ���������� ��������: ";
	cin >> numStudent;
	cout << endl;

	STUDENT* mas3 = new STUDENT[numStudent];
	for (int i = 0; i < numStudent; i++) {
		CompletStruct(mas3, i);
	}

	EnterAndSortStruct(mas3, numStudent);
	SearchFiveInMas(mas3, numStudent);
}
