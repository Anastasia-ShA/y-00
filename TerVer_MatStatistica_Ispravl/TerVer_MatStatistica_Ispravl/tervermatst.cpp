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
        cout << "\n����������� ������ ����������� � ��� ����������.";
        cout << "\n�������: \n0. ��������� � ������� ����\n1. ����������� m/n\n2. ��������� ��� ����������� ������������ �������\n3. ��� �������� ��� ����������� ������������� �������\n";
        cin >> deistvie;
        switch (deistvie)
        {
        case 1: veroyatnostM_N(); break;
        case 2:
            cout << "������� ���������� ��������� �������:";
            praviolnost_Vvoda_int(kolvo_slychaynix_velichin);
            if (Xi != nullptr) delete[] Xi;
            if (Pi != nullptr) delete[] Pi;
            Xi = new double[kolvo_slychaynix_velichin];
            Pi = new double[kolvo_slychaynix_velichin];
            dispersia();
            break;
        case 3:
            cout << "������� ���������� ��������� �������:";
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
        cout << "\n������ ���������? (yes/no): ";
        cin >> input;

        if (input == "y" || input == "yes") {
            return true;
        }
        else if (input == "n" || input == "no") {

            return false;
        }
        cout << "\n������! ����������, ������� 'yes' ��� 'no': ";
    }
}



void praviolnost_Vvoda(double& a) {
    while (!(cin >> a) || a <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n������! ������� ������������� ����� �����: ";
    }

}

void praviolnost_Vvoda_int(int& a) {
    while (!(cin >> a) || a <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n������! ������� ������������� ����� �����: ";
    }

}





bool provarkaM_N(int m, int n) {
    if (m > n) {
        cout << "\n������! m ������ ���� ������ n";
        return false;
    }
    return true;
}

void veroyatnostM_N() {
    do
    {
        do
        {
            cout << "\n������� ����� ������������� ������� m:";
            praviolnost_Vvoda(m);
            cout << "\n������� ����� ����� ������� n:";
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
            cerr << "������: ������� �� ����!" << endl;
            return 0.0;
        }
        return chislitel / znamenateli;
    }
    return stod(input);
}

void dispersiyaForDiskretnogoRaspVelichin() {
    cout << "\n������� " << kolvo_slychaynix_velichin << " ��������� ������� Xi: \n";
    for (int i = 0; i < kolvo_slychaynix_velichin; i++) {
        cout << "Xi[" << i << "] = ";
        cin >> Xi[i];
    }

    double sumPi = 0;
    cout << "\n������� " << kolvo_slychaynix_velichin << " �� ������������ Pi: \n";
    for (int i = 0; i < kolvo_slychaynix_velichin; i++) {
        cout << "Pi[" << i << "] = ";
        string input;
        cin >> input;
        Pi[i] = parseFraction(input);
        sumPi += Pi[i];
    }

    if (abs(sumPi - 1.0) > 1e-6) {
        cout << "������: ����� Pi ������ ���� ����� 1! ������� �����: " << sumPi << endl;
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
        cout << "��������� ��� ����������� ������������� �������: " << dispersion << endl;
    } while (GetYesOrNo());
}

void matOshidanie() {
    do {
        dispersiyaForDiskretnogoRaspVelichin();
        double Mx = 0;
        for (int i = 0; i < kolvo_slychaynix_velichin; i++) {
            Mx += Xi[i] * Pi[i];
        }
        cout << "��� �������� ��� ����������� ������������� �������: " << Mx << endl;
    } while (GetYesOrNo());
}