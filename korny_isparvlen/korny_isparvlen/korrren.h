#pragma once
bool GetYesOrNo();
auto vvod_a_b();
void metod_bisektsii(double a, double b, double (*func)(double));
void findAllKorny(double start, double end, double (*func)(double), int segments = 100);
double vozvedenie_v_stepen(double osnovanie, int stepen);
double podshett_polinom(double chislo);
double podshett_stepennoy(double chislo);
double podshett_pokazatelnoy(double chislo);
double podshett_logarifmichesok(double chislo);
double podshett_sinusoidnaya(double chislo);
double podshett_kosinusoida(double chislo);
void polinom();
void stepennaya();
void pokazatelnaya();
void logarifmisheskaya();
void sinusoidnaya();
void kosinusoida();
void korny();