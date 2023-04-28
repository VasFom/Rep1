#define _USE_MATH_DEFINES
#include<iostream>
#include<math.h>
#include<conio.h>

using namespace std;

void z1(float x) {
	cout << "Значение z1 при a = " << x << ":\t";
	cout << (cos(x) + sin(x) + cos(x * 3) + sin(x * 3)) << endl;
}

void z2(float x) {
	cout << "Значение z2 при a = " << x << ":\t";
	cout << (2 * sqrt(2) * cos(0) * sin(M_PI / 4 - 2 * 0)) << endl;
}

void main() {
	setlocale(LC_ALL, "rus");
	z1(0);
	z1(M_PI);
	z2(0);
	z2(M_PI);
	_getch();
}
//изменение