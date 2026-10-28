#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int N, i, j;
    int **matr = NULL;
    int **mas = NULL;
    int **res = NULL;

    printf("=== Програма 5_5 (Завдання 2) ===\n");
    printf("Двовимірні динамічні квадратні матриці\n\n");

    // 1. Введення розміру квадратних матриць
    printf("Введіть розмір квадратної матриці N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Помилка: некоректний розмір матриці!\n");
        return 1;
    }

    // 2. Виділення динамічної пам'яті під три матриці (matr, mas, res)
    matr = (int **)malloc(N * sizeof(int *));
    mas  = (int **)malloc(N * sizeof(int *));
    res  = (int **)malloc(N * sizeof(int *));

    if (matr == NULL || mas == NULL || res == NULL) {
        printf("Помилка виділення пам'яті для масивів покажчиків!\n");
        return -1;
    }

    for (i = 0; i < N; i++) {
        matr[i] = (int *)malloc(N * sizeof(int));
        mas[i]  = (int *)malloc(N * sizeof(int));
        res[i]  = (int *)malloc(N * sizeof(int));
        if (matr[i] == NULL || mas[i] == NULL || res[i] == NULL) {
            printf("Помилка виділення пам'яті для рядків матриці!\n");
            return -2;
        }
    }

    srand((unsigned int)time(NULL));

    // 3. Заповнення першої матриці matr випадковими числами до 100 (0..100)
    printf("\n--- Перша матриця matr (випадкові числа від 0 до 100) ---\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matr[i][j] = rand() % 101;
            printf("%6d", matr[i][j]);
        }
        printf("\n");
    }

    // 4. Заповнення другої матриці mas випадковими числами від -50 до +50
    printf("\n--- Друга матриця mas (випадкові числа від -50 до +50) ---\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            mas[i][j] = rand() % 101 - 50;
            printf("%6d", mas[i][j]);
        }
        printf("\n");
    }

    // 5. Формування третьої матриці res за умовою Варіанта 2:
    // Сума елементів перших двох матриць, якщо вона в діапазоні [60; 120], інакше 46 (код символу '.')
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            int sum = matr[i][j] + mas[i][j];
            if (sum >= 60 && sum <= 120) {
                res[i][j] = sum;
            } else {
                res[i][j] = 46;
            }
        }
    }

    // Виведення третьої матриці у числовому вигляді (коди ASCII)
    printf("\n--- Третя матриця res (числові значення: 60..120 або 46) ---\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%6d", res[i][j]);
        }
        printf("\n");
    }

    // Виведення третьої матриці у символьному вигляді (як вимагає завдання)
    printf("\n--- Третя матриця res (у символьному вигляді ASCII) ---\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%6c", (char)res[i][j]);
        }
        printf("\n");
    }

    // 6. Звільнення динамічної пам'яті
    for (i = 0; i < N; i++) {
        free(matr[i]);
        free(mas[i]);
        free(res[i]);
    }
    free(matr);
    free(mas);
    free(res);

    printf("\nДинамічну пам'ять усіх трьох матриць успішно звільнено.\n");

    return 0;
}
