#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <windows.h>

using namespace std;

#define MAX_LEN 256

// Прототипи функцій обробки рядка (Варіант 17)
int getStringLength(const char *s);
int countWords(const char *s);
int countDoubleSpaces(const char *s);
void showMenu();

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // Статичний масив для зберігання рядка
    char str[MAX_LEN];
    int choice;

    cout << "Введіть рядок: ";
    cin.getline(str, MAX_LEN);

    // Меню вибору дії у циклі do-while
    do {
        showMenu();
        cout << "Ваш вибір: ";
        if (!(cin >> choice)) {
            break;
        }

        switch (choice) {
            case 1:
                cout << "Довжина рядка: " << getStringLength(str) << endl;
                break;

            case 2:
                cout << "Кількість слів: " << countWords(str) << endl;
                break;

            case 3:
                cout << "Кількість подвійних пробілів: " << countDoubleSpaces(str) << endl;
                break;

            case 0:
                cout << "Вихід." << endl;
                break;

            default:
                cout << "Невірний вибір!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}

// Функція виведення меню
void showMenu()
{
    cout << "\nМеню:" << endl;
    cout << "1 - Довжина рядка" << endl;
    cout << "2 - Кількість слів" << endl;
    cout << "3 - Кількість подвійних пробілів" << endl;
    cout << "0 - Вихід" << endl;
}

// (1) Визначення довжини рядка через бібліотечну функцію strlen()
int getStringLength(const char *s)
{
    return (int)strlen(s);
}

// (2) Підрахунок кількості слів у рядку
int countWords(const char *s)
{
    int words = 0;
    bool inWord = false;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!isspace((unsigned char)s[i])) {
            if (!inWord) {
                words++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    return words;
}

// (3) Підрахунок кількості подвійних пробілів у рядку
int countDoubleSpaces(const char *s)
{
    int count = 0;
    int len = (int)strlen(s);

    for (int i = 0; i < len - 1; i++) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            count++;
        }
    }
    return count;
}
