#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Варіант 2 (для варіанта 17 у списку групи):
    // Введіть з клавіатури змінні a, b, c (типу double), 
    // обчисліть вираз res = a + 2.8*b - c^2 та виведіть на екран результат
    // з двома цифрами цілої частини і трьома – дробової.
    // Загальна кількість позицій: 2 (ціла частина) + 1 (крапка) + 3 (дробова частина) = 6.
    // Специфікатор: %6.3lf
    double a, b, c, res;

    puts("Input a, b, c (double):");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        puts("Error reading input!");
        return 1;
    }

    // c2 означає c^2 (квадрат числа c)
    res = a + 2.8 * b - (c * c);

    printf("a=%6.2lf, b=%6.2lf, c=%6.2lf\n", a, b, c);
    printf("res=%6.3lf\n", res);

    system("pause");
    return 0;
}
