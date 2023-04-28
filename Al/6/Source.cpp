#include <iostream>
using namespace std;
float CountMark(int* mas) {//��������� ������� ����
	float sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += mas[i];
	}
	return (sum / 5);
}
void CompletMas(int* mas, int numPeople) {
	cout << "������� ������ " << (numPeople + 1) << "-�� �������:" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> mas[i];
	}
}
bool CheckFiveInMas(int* mas) {
	for (int i = 0; i < 5; i++) {
		if (mas[i] == 5)
			return 1;
	}
	return 0;
}
struct STUDENT {
	string name;
	int numberOfGroup;
	int mark[5];
	float midMark;
};
void CompletStruct(STUDENT* mas, int numStruct) {
	cout << "������� ��� " << (numStruct + 1) << " - �� �������: ";
	cin >> mas[numStruct].name;
	cout << endl;
	cout << "������� ����� ������ " << (numStruct + 1) << "- �� �������: ";
	cin >> mas[numStruct].numberOfGroup;
	cout << endl;
	CompletMas(mas[numStruct].mark, numStruct);
}
void CopyData(STUDENT* mas, int numOut, int numIn) {//�������� ������ �� ��������� �
	mas[numIn].name = mas[numOut].name;				//� ������� numOut � ��������� � ������� 													//numIn
	mas[numIn].numberOfGroup = mas[numOut].numberOfGroup;
	for (int i = 0; i < 5; i++) {
		mas[numIn].mark[i] = mas[numOut].mark[i];
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	system("chcp 1251 > NULL");
	STUDENT mas[10];
	STUDENT* temp;
	string tempName;
	float tempMidMark;
	int tempMark[5];
	int tempNumOfGroup;
	int tempNumMark = 0;
	for (int i = 0; i < 10; i++) {
		CompletStruct(mas, i);
		tempMidMark = CountMark(mas[i].mark);
		cout << "������� ���� " << (i + 1) << "-�� �������:";
		cout << tempMidMark << endl << endl;
		for (int j = 0; j <= i; j++) {
			if (CountMark(mas[i].mark) < CountMark(mas[j].mark)) {
				tempNumMark = j;
				tempName = mas[i].name;
				tempNumOfGroup = mas[i].numberOfGroup;
				for (int t = 0; t < 5; t++) {
					tempMark[t] = mas[i].mark[t];
				}
				for (int k = i; k > tempNumMark; k--) {
					CopyData(mas, k - 1, k);
				}
				mas[tempNumMark].name = tempName;
				mas[tempNumMark].numberOfGroup = tempNumOfGroup;
				for (int t = 0; t < 5; t++) {
					mas[tempNumMark].mark[t] = tempMark[t];
				}
				break;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << "���: " << mas[i].name << endl;
		cout << "����� ������: " << mas[i].numberOfGroup << endl << endl;
		cout << "������� ���� " << (i + 1) << "-�� �������:";
		cout << CountMark(mas[i].mark) << endl << endl;
	}
	cout << "������ �����, ������� �������� ������ 5:" << endl;
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (CheckFiveInMas(mas[i].mark)) {
			cout << "���: " << mas[i].name << endl;
			cout << "����� ������: " << mas[i].numberOfGroup << endl << endl;
			count++;
		}
	}
	if (!count) {
		cout << "�����, ������� �������� ������ 5, ���" << endl;
	}
}
