#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool SearchWord(string text, int a, int b, string word) {//ищет слово в предложении
	int i;

	for (int j = a; j <= (b - word.size()); j++) {
		i = 0;
		while (text[j] == word[i]) {
			i++;
			j++;
		};
		if (i == word.size()) {
			return 1;
		}
	}
	return 0;
}

void main() {
	setlocale(LC_ALL, "rus");
	system("chcp 1251 > NULL");
	string filenameCT, text, out;
	string word = "строки";//слово, которое ищем
	cout << "Введите название файла для считывания:  ";
	cin >> filenameCT;
	cout << endl;
	ifstream inputFile(filenameCT, ios::binary);

	inputFile.seekg(0, fstream::end);
	int sizeFile = inputFile.tellg();
	inputFile.seekg(0, fstream::beg);
	text.resize(sizeFile);
	inputFile.read(&text[0], sizeFile);
	
	cout << "Исходный текст:" << endl;
	cout << text << endl;

	cout << "Введите ключевое слово:  ";
	cin >> word;
	cout << word << endl;

	int elem1, elem2;
	elem1 = elem2 = 0;
	int numStr = 0;

	cout << "Найденные предложения:" << endl;
	for (int i = 0; i < sizeFile; i++) {
		if ((text[i] == '.') || (text[i] == '?') || (text[i] == '!')) {
			if (SearchWord(text, elem1, i, word)) {
				out.resize(i - elem1 + 1);
				memcpy(&out[0], &text[elem1], (i - elem1 + 1));
				numStr++;
				cout << numStr << '.';
				cout << out << endl;
			}
			elem1 = i + 1;
		}
	}

	inputFile.close();
}