#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    // Варіант 2 (для варіанта 17 у списку групи)
    // Початкова ініціалізація змінних згідно із завданням
    short x1 = -32763, x2, x3;
    unsigned short y1 = 31, y2, y3;
    char z1 = -120, z2, z3;
    unsigned char v1 = 20, v2, v3;

    // 1. short (діапазон від -32768 до 32767)
    // Мінімальне значення = -32768
    x2 = x1 - 5; // -32763 - 5 = -32768 (мінімум)
    x3 = x1 - 6; // менше за мінімум на 1 -> переповнення (underflow) до 32767
    printf("short: x1=%d, min x2=%d, underflow x3=%d\n", x1, x2, x3);

    // 2. unsigned short (діапазон від 0 до 65535)
    // Мінімальне значення = 0
    y2 = y1 - 31; // 31 - 31 = 0 (мінімум)
    y3 = y1 - 32; // менше за мінімум на 1 -> переповнення до 65535
    printf("unsigned short: y1=%u, min y2=%u, underflow y3=%u\n", y1, y2, y3);

    // 3. char зі знаком (діапазон від -128 до 127)
    // Мінімальне значення = -128
    z2 = z1 - 8; // -120 - 8 = -128 (мінімум)
    z3 = z1 - 9; // менше за мінімум на 1 -> переповнення до 127
    printf("char: z1=%d, min z2=%d, underflow z3=%d\n", z1, z2, z3);

    // 4. unsigned char (діапазон від 0 до 255)
    // Мінімальне значення = 0
    v2 = v1 - 20; // 20 - 20 = 0 (мінімум)
    v3 = v1 - 21; // менше за мінімум на 1 -> переповнення до 255
    printf("unsigned char: v1=%u, min v2=%u, underflow v3=%u\n\n", v1, v2, v3);

    system("pause");
    return 0;
}
