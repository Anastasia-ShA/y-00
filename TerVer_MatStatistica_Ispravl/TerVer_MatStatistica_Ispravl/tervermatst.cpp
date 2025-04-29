#include <iostream>
#include <malloc.h>
#include <string>
#include "teer.h"

using namespace std;
int kolvo_slychaynix_velichin = 0;
double* Xi = new double[kolvo_slychaynix_velichin];
double* Pi = new double[kolvo_slychaynix_velichin];

double n;
double m;


void TerVer_MatStat() {
    int deistvie;
    do
    {
        cout << "\nКалькулятор теории вероятности и мат статистики.";
        cout << "\nФункции: \n0. Вернуться в главное меню\n1. Вероятность m/n\n2. Дисперсия для дискретного рапределения величин\n3. Мат ожидание для дискретного распределения величин\n";
        cin >> deistvie;
        switch (deistvie)
        {
        case 1: veroyatnostM_N(); break;
        case 2:
            cout << "Введите количество случайных величин:";
            praviolnost_Vvoda_int(kolvo_slychaynix_velichin);
            if (Xi != nullptr) delete[] Xi;
            if (Pi != nullptr) delete[] Pi;
            Xi = new double[kolvo_slychaynix_velichin];
            Pi = new double[kolvo_slychaynix_velichin];
            dispersia();
            break;
        case 3:
            cout << "Введите количество случайных величин:";
            praviolnost_Vvoda_int(kolvo_slychaynix_velichin);
            if (Xi != nullptr) delete[] Xi;
            if (Pi != nullptr) delete[] Pi;
            Xi = new double[kolvo_slychaynix_velichin];
            Pi = new double[kolvo_slychaynix_velichin];
            matOshidanie();
            break;
        default:
            break;
        }
    } while (deistvie != 0);
    if (Xi != nullptr) delete[] Xi;
    if (Pi != nullptr) delete[] Pi;
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
        cout << "\nОшибка! Пожалуйста, введите 'yes' или 'no': ";
    }
}



void praviolnost_Vvoda(double& a) {
    while (!(cin >> a) || a <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nОшибка! Введите положительное целое число: ";
    }

}

void praviolnost_Vvoda_int(int& a) {
    while (!(cin >> a) || a <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nОшибка! Введите положительное целое число: ";
    }

}





bool provarkaM_N(int m, int n) {
    if (m > n) {
        cout << "\nОшибка! m должно быть меньше n";
        return false;
    }
    return true;
}

void veroyatnostM_N() {
    do
    {
        do
        {
            cout << "\nВведите число благоприятных условий m:";
            praviolnost_Vvoda(m);
            cout << "\nВведите общее число условий n:";
            praviolnost_Vvoda(n);
        } while (!provarkaM_N(m, n));
        cout << m / n;

    } while (GetYesOrNo());


}

double parseFraction(const string& input) {
    size_t slash = input.find('/');
    if (slash != string::npos) {
        double chislitel = stod(input.substr(0, slash));
        double znamenateli = stod(input.substr(slash + 1));
        if (znamenateli == 0) {
            cerr << "Ошибка: деление на ноль!" << endl;
            return 0.0;
        }
        return chislitel / znamenateli;
    }
    return stod(input);
}

void dispersiyaForDiskretnogoRaspVelichin() {
    cout << "\nВведите " << kolvo_slychaynix_velichin << " случайных величин Xi: \n";
    for (int i = 0; i < kolvo_slychaynix_velichin; i++) {
        cout << "Xi[" << i << "] = ";
        cin >> Xi[i];
    }

    double sumPi = 0;
    cout << "\nВведите " << kolvo_slychaynix_velichin << " их вероятностей Pi: \n";
    for (int i = 0; i < kolvo_slychaynix_velichin; i++) {
        cout << "Pi[" << i << "] = ";
        string input;
        cin >> input;
        Pi[i] = parseFraction(input);
        sumPi += Pi[i];
    }

    if (abs(sumPi - 1.0) > 1e-6) {
        cout << "Ошибка: сумма Pi должна быть равна 1! Текущая сумма: " << sumPi << endl;
        return;
    }
}

void dispersia() {
    do {
        dispersiyaForDiskretnogoRaspVelichin();
        double Mx = 0;
        double Mx2 = 0;
        for (int i = 0; i < kolvo_slychaynix_velichin; i++) {
            Mx += Xi[i] * Pi[i];
            Mx2 += Xi[i] * Xi[i] * Pi[i];
        }
        double dispersion = Mx2 - (Mx * Mx);
        cout << "Дисперсия для дискретного распределения величин: " << dispersion << endl;
    } while (GetYesOrNo());
}

void matOshidanie() {
    do {
        dispersiyaForDiskretnogoRaspVelichin();
        double Mx = 0;
        for (int i = 0; i < kolvo_slychaynix_velichin; i++) {
            Mx += Xi[i] * Pi[i];
        }
        cout << "Мат ожидание для дискретного распределения величин: " << Mx << endl;
    } while (GetYesOrNo());
}