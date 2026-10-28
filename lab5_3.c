#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Масив з 3-х покажчиків на рядки
    // Завдання 3: назви університету, факультету (інституту), спеціальності
    const char *strings[] = {
        "Lviv Polytechnic National University",
        "ICTA",
        "Software Engineering and Information Systems"
    };

    int count_target = 0;
    int i;
    const char *ptr;

    printf("=== Програма 5_3 (Завдання 3) ===\n\n");

    // 1. Виведення рядків на екран
    printf("--- Рядки масиву покажчиків ---\n");
    for (i = 0; i < 3; i++) {
        printf("strings[%d]: %s (довжина strlen = %d символів)\n", i, strings[i], (int)strlen(strings[i]));
    }

    // 2. Визначення розмірів у пам'яті за допомогою sizeof
    printf("\n--- Розміри у пам'яті (sizeof) ---\n");
    printf("Розмір масиву покажчиків (strings):    %d байт\n", (int)sizeof(strings));
    printf("Розмір 1-го покажчика (strings[0]):     %d байт\n", (int)sizeof(strings[0]));
    printf("Розмір 2-го покажчика (strings[1]):     %d байт\n", (int)sizeof(strings[1]));
    printf("Розмір 3-го покажчика (strings[2]):     %d байт\n", (int)sizeof(strings[2]));

    // 3. Підрахунок кількості літер 'e' / 'E' (або кириличної 'е' / 'Е') у третьому рядку strings[2]
    ptr = strings[2];
    while (*ptr != '\0') {
        // Перевірка на латинську літеру 'e' / 'E'
        if (*ptr == 'e' || *ptr == 'E') {
            count_target++;
        }
        ptr++;
    }

    printf("\n--- Результат обчислення ---\n");
    printf("Аналізований 3-й рядок: \"%s\"\n", strings[2]);
    printf("Кількість букв 'e'/'E' у третьому рядку = %d\n", count_target);

    return 0;
}
