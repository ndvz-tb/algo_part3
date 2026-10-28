#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void)
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int n, i;
    float *ptr = NULL;

    printf("=== Програма 5_4 (Завдання 2) ===\n");
    printf("Динамічний масив типу float (malloc), діапазон [-50.5; +50.5]\n\n");

    // 1. Введення розміру масиву з клавіатури
    printf("Введіть розмір масиву n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Помилка: некоректний розмір масиву!\n");
        return 1;
    }

    // 2. Виділення динамічної пам'яті за допомогою функції malloc
    ptr = (float *)malloc(n * sizeof(float));
    if (ptr == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return -1;
    }

    // 3. Заповнення масиву випадковими числами у діапазоні від -50.5 до +50.5
    srand((unsigned int)time(NULL));
    for (i = 0; i < n; i++) {
        // Ширина діапазону: 50.5 - (-50.5) = 101.0 (від 0 до 1010 десятих)
        *(ptr + i) = (rand() % 1011) * 0.1f - 50.5f;
    }

    // 4. Виведення динамічного масиву на екран
    printf("\n--- Згенерований динамічний масив (%d елементів) ---\n", n);
    for (i = 0; i < n; i++) {
        printf("ptr[%d] = %6.1f\n", i, *(ptr + i));
    }

    // 5. Звільнення динамічної пам'яті
    free(ptr);
    ptr = NULL;
    printf("\nДинамічну пам'ять успішно звільнено (free).\n");

    return 0;
}
