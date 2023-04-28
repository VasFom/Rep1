#include "3.h"
#include "4.h"
#include "5.h"
#include "6.h"

void main() {
	setlocale(LC_ALL, "rus");
	system("chcp 1251 > NULL");
	///////////////////////////////Задание 3////////////////////
	//cout << "Задание 3 (double)" << endl;
	//int n;
	//cout << "Введите количество элементов массива:  ";
	//cin >> n;
	//cout << endl;
	//double* mas = new double[n];
	//for (int i = 0; i < n; i++) {
	//	cout << "Введите " << i << "-ый элемент массива: ";
	//	cin >> mas[i];
	//}

	//cout << "Сумма положительных элемнтов массива:  " << SumPositiveElem(mas, n) << endl;

	//cout << "Произведение элементов массива, располагающихся между минимальным и максимальным элементами:  " << MultElemBetween(mas, n) << endl;

	//QuickSort(mas, 0, n - 1);

	//cout << "Элементы массива после сортировки: ";
	//PrintMas(mas, n);

	//delete[] mas;
	//cout << "Задание 3 (int)" << endl;
	//int* mas2 = new int[n];
	//for (int i = 0; i < n; i++) {
	//	cout << "Введите " << i << "-ый элемент массива: ";
	//	cin >> mas2[i];
	//}

	//cout << "Сумма положительных элемнтов массива:  " << SumPositiveElem(mas2, n) << endl;

	//cout << "Произведение элементов массива, располагающихся между минимальным и максимальным элементами:  " << MultElemBetween(mas2, n) << endl;

	//QuickSort(mas2, 0, n - 1);

	//cout << "Элементы массива после сортировки: ";
	//PrintMas(mas2, n);

	//delete[] mas2;
	/////////////////////////////////Задание 4////////////////////
	//cout << "Задание 4 (double)" << endl;
	//cout << "Введите количество строк массива:  ";
	//cin >> n;

	//int m;
	//cout << "Введите количество столбцов массива:  ";
	//cin >> m;
	//cout << endl;

	//double** mas3 = new double* [n];
	//for (int i = 0; i < n; i++) {
	//	mas3[i] = new double[m];
	//	for (int j = 0; j < m; j++) {
	//		cout << "Введите " << j << "-ый элемент " << i << "-ой строки массива: ";
	//		cin >> mas3[i][j];
	//	}
	//}
	//cout << "Введённый массив" << endl;
	//PrintMas(mas3, n, m);
	//cout << endl;

	//cout << "Количество ненулевых столбцов:  " << CountNoNullCol(mas3, n, m) << endl;
	//SortByHar(mas3, n, m);
	//cout << "Элементы массива после сортировки: \n";
	//PrintMas(mas3, n, m);

	//for (int i = 0; i < n; i++) {
	//	delete[] mas3[i];
	//}
	//delete[] mas3;

	//cout << "Задание 4 (float)" << endl;
	//float** mas4 = new float* [n];
	//for (int i = 0; i < n; i++) {
	//	mas4[i] = new float[m];
	//	for (int j = 0; j < m; j++) {
	//		cout << "Введите " << j << "-ый элемент " << i << "-ой строки массива: ";
	//		cin >> mas4[i][j];
	//	}
	//}
	//cout << "Введённый массив" << endl;
	//PrintMas(mas4, n, m);
	//cout << endl;

	//cout << "Количество ненулевых столбцов:  " << CountNoNullCol(mas4, n, m) << endl;
	//SortByHar(mas4, n, m);
	//cout << "Элементы массива после сортировки: \n";
	//PrintMas(mas4, n, m);

	//for (int i = 0; i < n; i++) {
	//	delete[] mas4[i];
	//}
	//delete[] mas4;
	/////////////////////////////Задание 5////////////////////
	cout << "Задание 5" << endl;
	string filename;
	cout << "Введите название файла для считыания:" << endl;
	cin >> filename;

	ifstream inputFile(filename, ios::binary);
	string text;
	inputFile.seekg(0, fstream::end);
	int sizeFile = inputFile.tellg();
	inputFile.seekg(0, fstream::beg);
	text.resize(sizeFile);
	inputFile.read(&text[0], sizeFile);

	cout << "Исходный текст:" << endl;
	cout << text << endl;

	string word = "строки";//слово, которое ищем
	cout << "Введите ключевое слово:  ";
	cin >> word;
	cout << word << endl;
	TextProcess(text, sizeFile, word);
	inputFile.close();
}
	/////////////////////////////Задание 6////////////////////
	//cout << "Задание 6 (float)" << endl;
	//int numStudent;
	//cout << "Введите количество учеников: ";
	//cin >> numStudent;
	//cout << endl;

	//STUDENT<float>* mas5 = new STUDENT<float>[numStudent];
	//for (int i = 0; i < numStudent; i++) {
	//	CompletStruct(mas5, i);
	//}

	//EnterAndSortStruct(mas5, numStudent);
	//SearchFiveInMas(mas5, numStudent);

	//cout << "Задание 6 (double)" << endl;
	//STUDENT<double>* mas6 = new STUDENT<double>[numStudent];
	//for (int i = 0; i < numStudent; i++) {
	//	CompletStruct(mas6, i);
	//}

	//EnterAndSortStruct(mas6, numStudent);
	//SearchFiveInMas(mas6, numStudent);

