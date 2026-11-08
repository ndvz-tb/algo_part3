#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

#define N 5

// Прототипи функцій (Варіант 17)
void fillMatrix(int a[][N], int n);
void printMatrix(int a[][N], int n);
int sumForRow(int a[][N], int k);
void buildSumsArray(int a[][N], int s[], int n);
void printArray(int s[], int n);
int findMinSum(int s[], int n, int &minIdx);

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int matr[N][N];
    int s[N];

    srand((unsigned int)time(NULL));

    // 1. Заповнення квадратної матриці випадковими числами від -20 до 20
    fillMatrix(matr, N);

    // 2. Виведення вихідного двовимірного масиву на екран
    cout << "Вихідна матриця:" << endl;
    printMatrix(matr, N);

    // 3. Обчислення сум елементів вище поточного рядка k (i < k),
    //    але нижче головної діагоналі (j < i) та запис у масив s[k]
    buildSumsArray(matr, s, N);

    // 4. Виведення одновимірного масиву сум s[k] на екран
    cout << "\nОдновимірний масив сум s[k]:" << endl;
    printArray(s, N);

    // 5. Пошук найменшої із цих сум
    int minIdx = 0;
    int minVal = findMinSum(s, N, minIdx);

    cout << "\nНайменша сума: s[" << minIdx << "] = " << minVal << endl;

    return 0;
}

// Заповнення матриці випадковими числами від -20 до 20
void fillMatrix(int a[][N], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 41 - 20;
        }
    }
}

// Виведення двовимірної матриці на екран
void printMatrix(int a[][N], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

// Обчислення суми елементів вище рядка k (i < k) і нижче головної діагоналі (j < i)
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

// Формування одновимірного масиву s[k]
void buildSumsArray(int a[][N], int s[], int n)
{
    for (int k = 0; k < n; k++) {
        s[k] = sumForRow(a, k);
    }
}

// Виведення одновимірного масиву s[k] на екран
void printArray(int s[], int n)
{
    for (int k = 0; k < n; k++) {
        printf("s[%d] = %d\n", k, s[k]);
    }
}

// Пошук найменшої суми в масиві s[k]
int findMinSum(int s[], int n, int &minIdx)
{
    minIdx = 0;
    for (int k = 1; k < n; k++) {
        if (s[k] < s[minIdx]) {
            minIdx = k;
        }
    }
    return s[minIdx];
}
