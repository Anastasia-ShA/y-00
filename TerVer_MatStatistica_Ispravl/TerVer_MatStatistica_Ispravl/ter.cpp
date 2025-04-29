#include <iostream>
#include <malloc.h>
#include <string>
#include "teer.h"
#include <locale.h>

using namespace std;

int main() {
    setlocale(0, "Russian");
    TerVer_MatStat(); // Убрали void и добавили вызов функции
    return 0;
}