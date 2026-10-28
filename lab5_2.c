#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROWS 6
#define COLS 3

int main(void)
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    float A[ROWS][COLS];
    float sum_pos = 0.0f;
    int count_pos = 0;
    float avg_pos = 0.0f;
    int i, j;

    // Ініціалізація генератора випадкових чисел
    srand((unsigned int)time(NULL));

    printf("=== Програма 5_2 (Завдання 2) ===\n");
    printf("Розмір двовимірного масиву: %d рядків на %d стовпці\n", ROWS, COLS);
    printf("Діапазон випадкових дійсних чисел: від -25.0 до +65.0\n\n");

    // 1. Заповнення масиву випадковими числами
    // Спосіб доступу 1: розіменування покажчиків *(*(A + i) + j)
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            // Генерація чисел з точністю до одного десяткового знака від -25.0 до 65.0
            *(*(A + i) + j) = (rand() % 901) * 0.1f - 25.0f;
        }
    }

    // 2. Виведення масиву на екран
    // Спосіб доступу 2: зміщення від вказівника на рядок *(A[i] + j)
    printf("--- Згенерований двовимірний масив A[%d][%d] ---\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%9.2f", *(A[i] + j));
        }
        printf("\n");
    }

    // 3. Обчислення середнього арифметичного додатних елементів
    // Спосіб доступу 3: комбінація покажчика на рядок та індексу (*(A + i))[j]
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if ((*(A + i))[j] > 0.0f) {
                sum_pos += (*(A + i))[j];
                count_pos++;
            }
        }
    }

    // 4. Виведення результатів
    printf("\n--- Результати обчислень ---\n");
    if (count_pos > 0) {
        avg_pos = sum_pos / (float)count_pos;
        printf("Кількість додатних елементів: %d\n", count_pos);
        printf("Сума додатних елементів:      %.2f\n", sum_pos);
        printf("Середнє арифметичне додатних:  %.2f\n", avg_pos);
    } else {
        printf("Додатних елементів у масиві не знайдено.\n");
    }

    return 0;
}
