#include "3.h"
#include "4.h"
#include "5.h"
#include "6.h"

void main() {
	setlocale(LC_ALL, "rus");
	system("chcp 1251 > NULL");
	///////////////////////////////������� 3////////////////////
	//cout << "������� 3 (double)" << endl;
	//int n;
	//cout << "������� ���������� ��������� �������:  ";
	//cin >> n;
	//cout << endl;
	//double* mas = new double[n];
	//for (int i = 0; i < n; i++) {
	//	cout << "������� " << i << "-�� ������� �������: ";
	//	cin >> mas[i];
	//}

	//cout << "����� ������������� �������� �������:  " << SumPositiveElem(mas, n) << endl;

	//cout << "������������ ��������� �������, ��������������� ����� ����������� � ������������ ����������:  " << MultElemBetween(mas, n) << endl;

	//QuickSort(mas, 0, n - 1);

	//cout << "�������� ������� ����� ����������: ";
	//PrintMas(mas, n);

	//delete[] mas;
	//cout << "������� 3 (int)" << endl;
	//int* mas2 = new int[n];
	//for (int i = 0; i < n; i++) {
	//	cout << "������� " << i << "-�� ������� �������: ";
	//	cin >> mas2[i];
	//}

	//cout << "����� ������������� �������� �������:  " << SumPositiveElem(mas2, n) << endl;

	//cout << "������������ ��������� �������, ��������������� ����� ����������� � ������������ ����������:  " << MultElemBetween(mas2, n) << endl;

	//QuickSort(mas2, 0, n - 1);

	//cout << "�������� ������� ����� ����������: ";
	//PrintMas(mas2, n);

	//delete[] mas2;
	/////////////////////////////////������� 4////////////////////
	//cout << "������� 4 (double)" << endl;
	//cout << "������� ���������� ����� �������:  ";
	//cin >> n;

	//int m;
	//cout << "������� ���������� �������� �������:  ";
	//cin >> m;
	//cout << endl;

	//double** mas3 = new double* [n];
	//for (int i = 0; i < n; i++) {
	//	mas3[i] = new double[m];
	//	for (int j = 0; j < m; j++) {
	//		cout << "������� " << j << "-�� ������� " << i << "-�� ������ �������: ";
	//		cin >> mas3[i][j];
	//	}
	//}
	//cout << "�������� ������" << endl;
	//PrintMas(mas3, n, m);
	//cout << endl;

	//cout << "���������� ��������� ��������:  " << CountNoNullCol(mas3, n, m) << endl;
	//SortByHar(mas3, n, m);
	//cout << "�������� ������� ����� ����������: \n";
	//PrintMas(mas3, n, m);

	//for (int i = 0; i < n; i++) {
	//	delete[] mas3[i];
	//}
	//delete[] mas3;

	//cout << "������� 4 (float)" << endl;
	//float** mas4 = new float* [n];
	//for (int i = 0; i < n; i++) {
	//	mas4[i] = new float[m];
	//	for (int j = 0; j < m; j++) {
	//		cout << "������� " << j << "-�� ������� " << i << "-�� ������ �������: ";
	//		cin >> mas4[i][j];
	//	}
	//}
	//cout << "�������� ������" << endl;
	//PrintMas(mas4, n, m);
	//cout << endl;

	//cout << "���������� ��������� ��������:  " << CountNoNullCol(mas4, n, m) << endl;
	//SortByHar(mas4, n, m);
	//cout << "�������� ������� ����� ����������: \n";
	//PrintMas(mas4, n, m);

	//for (int i = 0; i < n; i++) {
	//	delete[] mas4[i];
	//}
	//delete[] mas4;
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
}
	/////////////////////////////������� 6////////////////////
	//cout << "������� 6 (float)" << endl;
	//int numStudent;
	//cout << "������� ���������� ��������: ";
	//cin >> numStudent;
	//cout << endl;

	//STUDENT<float>* mas5 = new STUDENT<float>[numStudent];
	//for (int i = 0; i < numStudent; i++) {
	//	CompletStruct(mas5, i);
	//}

	//EnterAndSortStruct(mas5, numStudent);
	//SearchFiveInMas(mas5, numStudent);

	//cout << "������� 6 (double)" << endl;
	//STUDENT<double>* mas6 = new STUDENT<double>[numStudent];
	//for (int i = 0; i < numStudent; i++) {
	//	CompletStruct(mas6, i);
	//}

	//EnterAndSortStruct(mas6, numStudent);
	//SearchFiveInMas(mas6, numStudent);

