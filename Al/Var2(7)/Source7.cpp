#include "3.h"
#include "4.h"
#include "5.h"
#include "6.h"

void main() {
	setlocale(LC_ALL, "rus");
	system("chcp 1251 > NULL");
	/////////////////////////////Задание 3////////////////////
	cout << "Задание 3" << endl;
	int n;
	cout << "Введите количество элементов массива:  ";
	cin >> n;
	cout << endl;
	float* mas = new float[n];
	for (int i = 0; i < n; i++) {
		cout << "Введите " << i << "-ый элемент массива: ";
		cin >> mas[i];
	}

	cout << "Сумма положительных элемнтов массива:  " << SumPositiveElem(mas, n) << endl;

	cout << "Произведение элементов массива, располагающихся между минимальным и максимальным элементами:  " << MultElemBetween(mas, n)<< endl;
	
	QuickSort(mas, 0, n - 1);

	cout << "Элементы массива после сортировки: ";
	PrintMas(mas, n);

	delete[] mas;
	/////////////////////////////Задание 4////////////////////
	cout << "Задание 4" << endl;
	cout << "Введите количество строк массива:  ";
	cin >> n;

	int m;
	cout << "Введите количество столбцов массива:  ";
	cin >> m;
	cout << endl;

	int** mas2 = new int* [n];
	for (int i = 0; i < n; i++) {
		mas2[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cout << "Введите " << j << "-ый элемент " << i << "-ой строки массива: ";
			cin >> mas2[i][j];
			//cout << endl;
		}
	}
	cout << "Введённый массив" << endl;
	PrintMas(mas2, n, m);
	cout << endl;

	cout << "Количество ненулевых столбцов:  " << CountNoNullCol(mas2, n, m) << endl;
	SortByHar(mas2, n, m);
	cout << "Элементы массива после сортировки: \n";
	PrintMas(mas2, n, m);

	for (int i = 0; i < n; i++) {
		delete[] mas2[i];
	}
	delete[] mas2;

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
	/////////////////////////////Задание 6////////////////////
	cout << "Задание 6" << endl;
	int numStudent;
	cout << "Введите количество учеников: ";
	cin >> numStudent;
	cout << endl;

	STUDENT* mas3 = new STUDENT[numStudent];
	for (int i = 0; i < numStudent; i++) {
		CompletStruct(mas3, i);
	}

	EnterAndSortStruct(mas3, numStudent);
	SearchFiveInMas(mas3, numStudent);
}
