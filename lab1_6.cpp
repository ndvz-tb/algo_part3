#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define STR1 "Today we are"
#define STR2 "learning how to "
#define STR3 "\"Programm on C++\""

// Варіант 2 (для варіанта 17 у списку групи):
// Рядок STR4 з двома заданими словами: Прізвище та ім'я студента
#define STR4 "Nedoviz Taras"
#define STR4_FIRST "Nedoviz"

int main()
{
    // Початкова демонстраційна частина з методички
    printf("|%s|\n", STR1);
    printf("|%70.12s|\n", STR2);
    printf("|%70.24s|\n\n", STR3);
    printf("|%20.5s|\n", STR1);
    printf("|%20.8s|\n", STR2);
    printf("|%-20.9s|\n\n", STR3);

    // Доповнення до програми:
    // Стандартна ширина текстового рядка консолі становить 80 позицій (2 символи '|' + 78 позицій між ними)

    // 1. Слова повністю (з межами '|' на початку та в кінці рядка екрана)
    printf("|%-78s|\n", STR4);

    // 2. На новому рядку тільки перше слово спочатку рядка екрана (вирівнювання по лівому краю)
    printf("|%-78s|\n", STR4_FIRST);

    // 3. На наступному рядку перше слово в кінці рядка екрана (вирівнювання по правому краю)
    printf("|%78s|\n", STR4_FIRST);

    system("pause");
    return 0;
}
