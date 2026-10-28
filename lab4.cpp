#include <iostream>
#include <cstdio>
#include <cmath>
#include <windows.h>

using namespace std;

// Прототипи функцій згідно з методичними вказівками (п. 5.4)
double sum1(double x, int n);
double sum2(double x, float eps);
double term(double x, int k);
double y(double x);

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int n;
    float eps;
    double x, sn, se, exact_y;

    cout << "=== Лабораторна робота: Розділ 5 (Комп'ютерний практикум 4) ===" << endl;
    cout << "Тема: Функції. Ітераційні процеси. Варіант 17" << endl;
    cout << "Функція: y(x) = (e^x + e^(-x)) / 2,  0 <= x <= 1" << endl << endl;

    // Уведення n та точності eps (за замовчуванням у варіанті 17: n = 5, eps = 0.0001)
    cout << "Введіть кількість членів ряду n (наприклад, 5): ";
    cin >> n;
    cout << "Введіть точність обчислень eps (наприклад, 0.0001): ";
    cin >> eps;

    // Заголовок таблиці результатів
    printf("\n------------------------------------------------------------\n");
    printf("   x          Sn             Se             y(x)\n");
    printf("------------------------------------------------------------\n");

    // Ініціалізація інтервалів зміни аргументу: 0 <= x <= 1
    double x1 = 0.0;
    double x2 = 1.0;

    // Цикл по 10 точках на відрізку [x1; x2] згідно з блок-схемою (мал. 5.1)
    for (int j = 1; j <= 10; j++) {
        x = x1 + (x2 - x1) * (j - 1) / 9.0;
        sn = sum1(x, n);
        se = sum2(x, eps);
        exact_y = y(x);

        printf("%6.4f    %12.7f   %12.7f   %12.7f\n", x, sn, se, exact_y);
    }
    printf("------------------------------------------------------------\n");

    return 0;
}

// Функція обчислення суми ряду Sn при фіксованому n
double sum1(double x, int n)
{
    double z = 0.0;
    for (int k = 0; k <= n; k++) {
        z += term(x, k);
    }
    return z;
}

// Функція обчислення суми ряду Se із заданою точністю eps
double sum2(double x, float eps)
{
    double z = 0.0, ak = 1.0;
    int k = 0;
    while (fabs(ak) > eps) {
        ak = term(x, k);
        z += ak;
        k++;
    }
    return z;
}

// Функція обчислення k-го члена ряду: a_k = x^(2k) / (2k)!
double term(double x, int k)
{
    if (k == 0)
        return 1.0;

    double fact = 1.0;
    for (int i = 1; i <= 2 * k; i++) {
        fact *= i;
    }
    return pow(x, 2 * k) / fact;
}

// Функція обчислення точного значення y(x) = (e^x + e^(-x)) / 2
double y(double x)
{
    return (exp(x) + exp(-x)) / 2.0;
}
