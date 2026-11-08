#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

#define N 5

// Прототипи функцій згідно з варіантом 17 (Розділ 8, п. 8.3)
void fillMatrix(int a[][N], int n);
void printMatrix(int a[][N], int n);
int sumForRow(int a[][N], int k);
void buildSumsArray(int a[][N], int s[], int n);
void printArray(int s[], int n);
int findMinSum(int s[], int n, int startIdx, int &minIdx);

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int matr[N][N];
    int s[N];

    srand((unsigned int)time(NULL));

    cout << "=== Лабораторна робота №5 (Розділ 8: Комп'ютерний практикум 7) ===" << endl;
    cout << "Тема: Двовимірні масиви й функції. Варіант 17" << endl;
    cout << "Розмір квадратної матриці: " << N << "x" << N << ", діапазон чисел: [-20; 20]" << endl << endl;

    // 1. Заповнення квадратної матриці випадковими числами від -20 до 20 (функція)
    fillMatrix(matr, N);

    // 2. Виведення вихідної двовимірної матриці на екран (функція)
    cout << "--- Вихідна квадратна матриця matr[" << N << "][" << N << "] ---" << endl;
    printMatrix(matr, N);

    // 3. Обчислення сум елементів вище поточного рядка k (i < k),
    //    але нижче головної діагоналі (j < i) та запис у масив s[k] (функція)
    buildSumsArray(matr, s, N);

    // 4. Виведення одновимірного масиву сум s[k] на екран (функція)
    cout << "\n--- Одновимірний масив сум s[k] (умова: 0 <= j < i < k) ---" << endl;
    printArray(s, N);

    // 5. Пошук найменшої із цих сум (функція)
    int minIdxAll = 0, minIdxActive = 2;
    int minAll = findMinSum(s, N, 0, minIdxAll);
    int minActive = findMinSum(s, N, 2, minIdxActive);

    cout << "\n--- Результати пошуку найменшої суми ---" << endl;
    printf("Найменша сума серед усіх елементів s[0..%d]:      s[%d] = %d\n", N - 1, minIdxAll, minAll);
    printf("Найменша сума серед непорожніх областей s[2..%d]: s[%d] = %d\n", N - 1, minIdxActive, minActive);

    return 0;
}

// Функція ініціалізації матриці випадковими числами з діапазону [-20; 20]
void fillMatrix(int a[][N], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 41 - 20; // від -20 до +20
        }
    }
}

// Функція виведення двовимірної матриці на екран
void printMatrix(int a[][N], int n)
{
    printf("      ");
    for (int j = 0; j < n; j++) {
        printf(" [j=%d]", j);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("[i=%d] ", i);
        for (int j = 0; j < n; j++) {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
}

// Функція обчислення суми елементів вище поточного рядка k (i < k),
// але нижче головної діагоналі (j < i)
int sumForRow(int a[][N], int k)
{
    int sum = 0;
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < i; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

// Функція формування одновимірного масиву сум s[k]
void buildSumsArray(int a[][N], int s[], int n)
{
    for (int k = 0; k < n; k++) {
        s[k] = sumForRow(a, k);
    }
}

// Функція виведення одновимірного масиву s[k] на екран
void printArray(int s[], int n)
{
    for (int k = 0; k < n; k++) {
        if (k < 2) {
            printf("s[%d] = %4d  (вище рядка %d немає елементів під головною діагоналлю)\n", k, s[k], k);
        } else {
            printf("s[%d] = %4d  (сума елементів з індексами 0 <= j < i < %d)\n", k, s[k], k);
        }
    }
}

// Функція пошуку найменшого елемента в одновимірному масиві сум s[k]
int findMinSum(int s[], int n, int startIdx, int &minIdx)
{
    minIdx = startIdx;
    for (int k = startIdx + 1; k < n; k++) {
        if (s[k] < s[minIdx]) {
            minIdx = k;
        }
    }
    return s[minIdx];
}
