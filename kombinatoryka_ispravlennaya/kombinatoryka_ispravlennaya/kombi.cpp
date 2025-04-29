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
		cout << "\n����������� ������ �������������.";
		cout << "\n\b�������: \n0. ��������� � ������� ����\n1. ���������� � �����������\n2. ���������� ��� ����������\n3. ��������� � �����������\n4. ��������� ��� ����������\n5. ������������ ��� ����������\n6. ������������ � ������������\n�������� ����� ��������: ";
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
		cout << "\n������ ���������? (yes/no): ";
		cin >> input;

		if (input == "y" || input == "yes") {
			return true;
		}
		else if (input == "n" || input == "no") {
			return false;
		}
		cout << "������! ����������, ������� 'yes' ��� 'no': ";
	}
}

void pravilnost_Vvoda(int a, int b) {

	cout << "������� n (������ ���� ������������� �����): ";
	while (!(cin >> n) || n <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "������! ������� ������������� ����� �����: ";
	}

	if (b != 1) {
		cout << "������� m (������ ���� ������������� �����): ";
		while (!(cin >> m) || m <= 0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "������! ������� ������������� ����� �����: ";
		}
	}
}

void pravilnost_Vvoda2(int& a) {
	while (!(cin >> a) || a <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "������! ������� ������������� ����� �����: ";
	}

}

bool proverkaM_N(int n, int m) {
	if (m > n) {
		cout << "������ m ������ ���� ������ ��� ����� n";
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

	cout << "������� �����: "; cin >> slovo;
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
		cout << "\nC�������� ��������� ����� ������� � ���������� �� m ��������� ������ m �� n ���������, ����� ������� ���� ����������?\n";
		pravilnost_Vvoda(n, m);
		vozvedenie_V_steven(n, m);
	} while (GetYesOrNo());
}

void Razmechenie_Bez_Povtoreniy() {
	do
	{
		cout << "\nC�������� ��������� ����� ������� � ���������� �� m ��������� ������ m �� n ��������� ���������?\n";
		do
		{
			cout << "\n������� n (������ ���� ������������� �����):\n";
			pravilnost_Vvoda2(n);
			cout << "\n������� m (������ ���� ������������� �����):\n";
			pravilnost_Vvoda2(m);

		} while (!proverkaM_N(n, m));
		cout << factorial(n) / factorial(n - m);


	} while (GetYesOrNo());
}

void Sochetanie_S_Povtoreniem() {
	do
	{
		cout << "\nC�������� ��������� ����� ������� m (5) �� ���� (n*r) ���������?\n";
		pravilnost_Vvoda(n, m);
		cout << factorial(n + m - 1) / (factorial(m) * factorial(n - 1));
	} while (GetYesOrNo());

}

void Sochetanie_Bez_Povtoreniy() {
	do
	{
		cout << "\nC�������� ��������� ����� ������� m �� n ��������� ���������?\n";
		do
		{
			cout << "\n������� n (������ ���� ������������� �����):\n";
			pravilnost_Vvoda2(n);
			cout << "\n������� m (������ ���� ������������� �����):\n";
			pravilnost_Vvoda2(m);
		} while (!proverkaM_N(n, m));

		cout << factorial(n) / (factorial(m) * factorial(n - m));
	} while (GetYesOrNo());
}

void Perestanovka_Bez_Povtoreniy() {
	do
	{
		cout << "\nC�������� ��������� ����� ���������� n ��������� ��������� �� n ��������� ������?\n";
		//pravilnost_Vvoda(n, 1);
		cout << "������� n (������ ���� ������������� �����): ";
		pravilnost_Vvoda2(n);
		cout << factorial(n);
	} while (GetYesOrNo());
}

void Bykvy() {
	cout << "������� ���������� ���� � ����� (������ ���� ������������� �����): ";
	while (!(cin >> n) || n <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "������! ������� ������������� ����� �����: ";
	}
	cout << "������� ���������� ���������� ����: ";
	while (!(cin >> m) || m <= 0 || m > n) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "������! ������� ������������� ����� �����: ";
	}

	int res = 1;
	for (int i = 0; i < m; ++i) {
		int k;
		cout << "������� ���������� ���������� ��� ���������� ����� " << (i + 1) << ": ";
		while (!(cin >> k) || k <= 0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "������! ������� ������������� ����� �����: ";
		}
		res *= factorial(k);

	}
	cout << factorial(n) / res;
}

void Perestanovka_S_Povtoreniyami() {
	int choise;
	do
	{
		cout << "\nC�������� ��������� ����� ����������� n ���������, ������������� �� n ��������� ������, ���� ����� n ��������� ������� k ��������� ����� (k < n), �. �. ���� ���������� ��������\n";
		cout << "�������� ����� �������� �� ������ ������\n1)-������ �����\n2)-������ ���������� ������ ����� � �����\n"; cin >> choise;
		switch (choise)
		{
		case 1:ObrabotkaSlova(); break;
		case 2:Bykvy(); break;
		default:break;
		}

	} while (GetYesOrNo());

}

