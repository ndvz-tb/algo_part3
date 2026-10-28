#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 6

int main(void)
{
    int arr[ROWS][COLS];
    int count_row[ROWS];
    int total_count = 0;
    int i, j;

    printf("=== Програма 5_1 (Завдання 2) ===\n");
    printf("Розмір двовимірного масиву: %d рядки на %d стовпців\n\n", ROWS, COLS);

    // Введення елементів масиву з клавіатури
    printf("Введіть елементи масиву (%d цілих чисел):\n", ROWS * COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("arr[%d][%d] = ", i, j);
            if (scanf("%d", &arr[i][j]) != 1) {
                printf("Помилка введення даних!\n");
                return 1;
            }
        }
    }

    // Виведення масиву на екран у вигляді матриці
    printf("\n--- Введений двовимірний масив arr[%d][%d] ---\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%6d", arr[i][j]);
        }
        printf("\n");
    }

    // Обчислення кількості додатних парних елементів у кожному рядку
    printf("\n--- Результати обчислень (додатні парні елементи: x > 0 та x %% 2 == 0) ---\n");
    for (i = 0; i < ROWS; i++) {
        count_row[i] = 0;
        for (j = 0; j < COLS; j++) {
            if (arr[i][j] > 0 && arr[i][j] % 2 == 0) {
                count_row[i]++;
            }
        }
        printf("Рядок %d: кількість додатних парних елементів = %d\n", i, count_row[i]);
        total_count += count_row[i];
    }

    printf("\nЗагальна кількість додатних парних елементів у всьому масиві = %d\n", total_count);

    return 0;
}
