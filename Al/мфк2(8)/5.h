#pragma once
#pragma once
#include <string>
#include <fstream>
using namespace std;
template <typename T>
bool SearchWord(T text, int a, int b, string word) {//ищет слово в предложении
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
template <typename T>
void TextProcess(T text, int sizeFile, string word) {
	int elem1, elem2;
	elem1 = elem2 = 0;
	int numStr = 0;
	T out;
	cout << "Ќайденные предложени€:" << endl;
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
}
