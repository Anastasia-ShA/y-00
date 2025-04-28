#include <iostream>
#include <locale>
#include <malloc.h>
#include <cmath>
using namespace std;

double x;
int n;
double* Znacheniapolinoma;
double a, b;

double A_step, B_step, C_step, D_step;
double B_sin, C_sin, D_sin, A_sin;
double A_cos, B_cos, C_cos, D_cos;
double podshett_polinom(double chislo);
double podshett_stepennoy(double chislo);

bool GetYesOrNo() {
  string input;

  while (true) {
    cout << "\nХотите повторить? (yes/no): ";
    cin >> input;

    if (input == "y"  || input == "yes"){
       return true;
    }
    else if(input == "n"  || input == "no") {
     
    return false;
    }
    cout << "Ошибка! Пожалуйста, введите 'yes' или 'no': ";
  }
}

auto vvod_a_b() {
    cout << "Введите значения границы отрезка, где a = "; cin >> a; cout << "b = "; cin >> b;
}

void metod_bisektsii(double a, double b, double (*func)(double)) {
    const double toshnost = 1e-6;
    const int Maximalnoe_Kolvo_vichisleniy = 10000;
    double c;

    double fa = func(a);
    double fb = func(b);

    //cout << "f(a) = " << fa << endl;
    //cout << "f(b) = " << fb << endl;

    if (fa * fb >= 0) {
        cout << "Функция должна иметь разные знаки на концах отрезка";
        return;
    }

    for (int i = 0; i < Maximalnoe_Kolvo_vichisleniy; i++) {
        c = (a + b) / 2;
        double fc = func(c);

        if (abs(fc) < toshnost || (b - a) / 2 < toshnost) {
            cout << "Найден корень: x = " << c << endl;
            return;
        }

        if (fc * fa < 0) {
            b = c;
            fb = fc;
        }
        else {
            a = c;
            fa = fc;
        }
    }

    cout << "Достигнуто максимальное количество итераций" << endl;
}

void findAllKorny(double start, double end, double (*func)(double), int segments = 100) {
    double step = (end - start) / segments;

    for (int i = 0; i < segments; ++i) {
        double segment_start = start + i * step;
        double segment_end = segment_start + step;

        double fa = func(segment_start);
        double fb = func(segment_end);

        if (fa * fb < 0) {
            metod_bisektsii(segment_start, segment_end, func);
        }
    }
}

double vozvedenie_v_stepen(double osnovanie, int stepen) {
    if (stepen == 0) return 1;
    if (stepen == 1) return osnovanie;
    double half = vozvedenie_v_stepen(osnovanie, stepen / 2);
    if (stepen % 2 == 0)
        return half * half;
    else
        return half * half * osnovanie;
}

double podshett_polinom(double chislo) {
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        sum += Znacheniapolinoma[i] * vozvedenie_v_stepen(chislo, i);
    }
    return sum;
}

double podshett_stepennoy(double chislo) {
    return A_step * vozvedenie_v_stepen(chislo, B_step) + C_step;
}

double podshett_pokazatelnoy(double chislo) {
    return A_step * pow(B_step, C_step*chislo)+D_step;

}

double podshett_logarifmichesok(double chislo) {
    if (chislo * B_step <= 0) {
        cout << "Логарифм не определен при x = " << chislo << endl;
        return 0;
    }
    return A_step * log(B_step * chislo) + C_step;
}

double podshett_sinusoidnaya(double chislo) {
    return A_sin * sin(B_sin * chislo + C_sin) + D_sin;
}


double podshett_kosinusoida(double chislo) {
    return A_cos * cos(B_cos * chislo + C_cos) + D_cos;
}

void polinom() {
    do
    {

    
        do {
            cout << "\nВведите степень полинома n = ";
            cin >> n;
            if (n <= 0) {
                cout << "Степень полинома должна быть положительной\n";
            }
        } while (n <= 0);

        delete[] Znacheniapolinoma;
        Znacheniapolinoma = new double[n + 1];

        cout << "Введите коэффициенты полинома:\n";
        for (int i = 0; i < n + 1; i++) {
            cout << "a[" << i << "] = ";
            cin >> Znacheniapolinoma[i];
        }
        vvod_a_b();
        findAllKorny(a, b, podshett_polinom);
    } while (GetYesOrNo());
}

void stepennaya() {
    do
    {
        cout << "Введите значения для степенной функции:\nA = "; cin >> A_step;
        cout << "B = "; cin >> B_step;
        cout << "C = "; cin >> C_step;
        vvod_a_b();
        findAllKorny(a, b, podshett_stepennoy);
    } while (GetYesOrNo());
}

void pokazatelnaya() {
    do
    {

        cout << "Введите значения для показательной функции:\nA = "; cin >> A_step;
        cout << "B = "; cin >> B_step;
        cout << "C = "; cin >> C_step;
        cout << "D = "; cin >> D_step;
        vvod_a_b();
        findAllKorny(a, b, podshett_pokazatelnoy);
    } while (GetYesOrNo());
}

void logarifmisheskaya() {
    do
    {

        cout << "Введите значения для показательной функции:\nA = "; cin >> A_step;
        cout << "B = "; cin >> B_step;
        cout << "C = "; cin >> C_step;
        vvod_a_b();
        findAllKorny(a, b, podshett_logarifmichesok);
    } while (GetYesOrNo());
}


void sinusoidnaya() {
    do
    {

        cout << "Введите значения для синусоиды:\nA = "; cin >> A_sin;
        cout << "B = "; cin >> B_sin;
        cout << "C = "; cin >> C_sin;
        cout << "D = "; cin >> D_sin;
        vvod_a_b();
        findAllKorny(a, b, podshett_sinusoidnaya, 10000);
    } while (GetYesOrNo());
}

void kosinusoida() {
    do
    {

        cout << "Введите значения для косинусоиды:\nA = "; cin >> A_cos;
        cout << "B = "; cin >> B_cos;
        cout << "C = "; cin >> C_cos;
        cout << "D = "; cin >> D_cos;
        vvod_a_b();
        findAllKorny(a, b, podshett_kosinusoida, 10000);
    } while (GetYesOrNo());

}