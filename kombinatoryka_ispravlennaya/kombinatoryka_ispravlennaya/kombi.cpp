int m;
int n;

#include <map>
#include <cstring>
using namespace std;
#include <iostream>
#include <string>
#include <algorithm>
#include "kooombi.h"

void kombinator() {

	int deistvie;


	do
	{
		cout << "\nКалькулятор формул комбинаторики.";
		cout << "\n\bФункции: \n0. Вернуться в главное меню\n1. Размещение с повторением\n2. Размещение без повторений\n3. Сочетание с повторением\n4. Сочетание без повторений\n5. Перестановка без повторений\n6. Перестановка с повторениями\nВыберите номер действия: ";
		cin >> deistvie;
		switch (deistvie)
		{
		case 1: Razmechenie_S_Povtoreniem(); break;
		case 2:Razmechenie_Bez_Povtoreniy(); break;
		case 3:Sochetanie_S_Povtoreniem(); break;
		case 4:Sochetanie_Bez_Povtoreniy(); break;
		case 5:Perestanovka_Bez_Povtoreniy(); break;
		case 6:Perestanovka_S_Povtoreniyami(); break;
		default:
			break;
		}

	} while (deistvie != 0);
}

bool GetYesOrNo() {
	string input;

	while (true) {
		cout << "\nХотите повторить? (yes/no): ";
		cin >> input;

		if (input == "y" || input == "yes") {
			return true;
		}
		else if (input == "n" || input == "no") {
			return false;
		}
		cout << "Ошибка! Пожалуйста, введите 'yes' или 'no': ";
	}
}

void pravilnost_Vvoda(int a, int b) {

	cout << "Введите n (должно быть положительным целым): ";
	while (!(cin >> n) || n <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Ошибка! Введите положительное целое число: ";
	}

	if (b != 1) {
		cout << "Введите m (должно быть положительным целым): ";
		while (!(cin >> m) || m <= 0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Ошибка! Введите положительное целое число: ";
		}
	}
}

void pravilnost_Vvoda2(int& a) {
	while (!(cin >> a) || a <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Ошибка! Введите положительное целое число: ";
	}

}

bool proverkaM_N(int n, int m) {
	if (m > n) {
		cout << "Ошибка m должно быть меньше или равно n";
		return false;
	}
	return true;
}


int factorial(int a) {
	int res = 1;
	if (a == 0 || a == 1)return 1;
	else {
		for (int i = 1; i <= a; i++) {
			res *= i;
		}
		return res;
	}
}

void ObrabotkaSlova() {
	char slovo[100];

	cout << "Введите слово: "; cin >> slovo;
	int k = strlen(slovo);
	map<char, int> letterCounts;
	int res = 1;
	for (int i = 0; i < k; ++i) {
		char ch = slovo[i];
		letterCounts[ch]++;
	}
	for (const auto& pair : letterCounts) {
		res *= factorial(pair.second);
	}
	cout << factorial(k) / res;

}

void vozvedenie_V_steven(int a, int b) {
	int res = 1;
	for (int i = 0; i < b; i++) {
		res *= a;
	}
	cout << res;
}

void Razmechenie_S_Povtoreniem() {
	do {
		cout << "\nCколькими способами можно выбрать и разместить по m различным местам m из n предметов, среди которых есть одинаковые?\n";
		pravilnost_Vvoda(n, m);
		vozvedenie_V_steven(n, m);
	} while (GetYesOrNo());
}

void Razmechenie_Bez_Povtoreniy() {
	do
	{
		cout << "\nCколькими способами можно выбрать и разместить по m различным местам m из n различных предметов?\n";
		do
		{
			cout << "\nВведите n (должно быть положительным целым):\n";
			pravilnost_Vvoda2(n);
			cout << "\nВведите m (должно быть положительным целым):\n";
			pravilnost_Vvoda2(m);

		} while (!proverkaM_N(n, m));
		cout << factorial(n) / factorial(n - m);


	} while (GetYesOrNo());
}

void Sochetanie_S_Povtoreniem() {
	do
	{
		cout << "\nCколькими способами можно выбрать m (5) из этих (n*r) предметов?\n";
		pravilnost_Vvoda(n, m);
		cout << factorial(n + m - 1) / (factorial(m) * factorial(n - 1));
	} while (GetYesOrNo());

}

void Sochetanie_Bez_Povtoreniy() {
	do
	{
		cout << "\nCколькими способами можно выбрать m из n различных предметов?\n";
		do
		{
			cout << "\nВведите n (должно быть положительным целым):\n";
			pravilnost_Vvoda2(n);
			cout << "\nВведите m (должно быть положительным целым):\n";
			pravilnost_Vvoda2(m);
		} while (!proverkaM_N(n, m));

		cout << factorial(n) / (factorial(m) * factorial(n - m));
	} while (GetYesOrNo());
}

void Perestanovka_Bez_Povtoreniy() {
	do
	{
		cout << "\nCколькими способами можно разместить n различных предметов на n различных местах?\n";
		//pravilnost_Vvoda(n, 1);
		cout << "Введите n (должно быть положительным целым): ";
		pravilnost_Vvoda2(n);
		cout << factorial(n);
	} while (GetYesOrNo());
}

void Bykvy() {
	cout << "Введите количество букв в слове (должно быть положительным целым): ";
	while (!(cin >> n) || n <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Ошибка! Введите положительное целое число: ";
	}
	cout << "Введите количество уникальных букв: ";
	while (!(cin >> m) || m <= 0 || m > n) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Ошибка! Введите положительное целое число: ";
	}

	int res = 1;
	for (int i = 0; i < m; ++i) {
		int k;
		cout << "Введите количество повторений для уникальной буквы " << (i + 1) << ": ";
		while (!(cin >> k) || k <= 0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Ошибка! Введите положительное целое число: ";
		}
		res *= factorial(k);

	}
	cout << factorial(n) / res;
}

void Perestanovka_S_Povtoreniyami() {
	int choise;
	do
	{
		cout << "\nCколькими способами можно переставить n предметов, расположенных на n различных местах, если среди n предметов имеются k различных типов (k < n), т. е. есть одинаковые предметы\n";
		cout << "Выверите каким способом вы хотите ввести\n1)-Ввести слово\n2)-Ввести количество каждой буквы в слове\n"; cin >> choise;
		switch (choise)
		{
		case 1:ObrabotkaSlova(); break;
		case 2:Bykvy(); break;
		default:break;
		}

	} while (GetYesOrNo());

}

