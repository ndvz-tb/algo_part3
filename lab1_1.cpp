#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    puts("My first program"); // Виведення вітального повідомлення

    // Доповнення до програми:
    // 1. Виведення прізвища студента
    puts("Nedoviz");

    // 2. Виведення першої букви імені з кодами ASCII у різних системах числення
    char s = 'T'; // Перша буква імені (наприклад, Тарас)
    printf("Symbol %c = (%d)10S = (%#o)8S ", s, s, s);
    printf("= (%#x)16S size char=%d bait\n", s, (int)sizeof(s));

    int a = 78; // Визначення цілої змінної
    printf("a=%d size int=%d bait\n", a, (int)sizeof(a));

    float b = 56.23f; // Визначення дійсної змінної
    printf("b=%f=%e size float=%d bait\n", b, b, (int)sizeof(b));

    // 3. Визначення нових змінних типів short, long, double
    short sh = -1234;
    long lg = 987654321L;
    double db = 3.141592653589793;

    printf("sh=%d size short=%d bait\n", sh, (int)sizeof(sh));
    printf("lg=%ld size long=%d bait\n", lg, (int)sizeof(lg));
    printf("db=%lf size double=%d bait\n", db, (int)sizeof(db));

    puts("\nPress any key and Enter...\n");
    getchar();
    return 0;
}
