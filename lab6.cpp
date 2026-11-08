#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <windows.h>

using namespace std;

#define MAX_LEN 256

// Прототипи функцій обробки рядка згідно з варіантом 17 (Розділ 10, п. 10.3–10.4)
int getStringLength(const char *s);
int countWords(const char *s);
int countDoubleSpaces(const char *s);
void showMenu();

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // Статичний масив для зберігання рядка (п. 10.4 методичних вказівок)
    char str[MAX_LEN];
    int choice;

    cout << "=== Лабораторна робота №6 (Розділ 10: Комп'ютерний практикум 9) ===" << endl;
    cout << "Тема: Рядки. Варіант 17" << endl << endl;

    cout << "Введіть рядок символів:" << endl << "> ";
    cin.getline(str, MAX_LEN);

    cout << "\nВведений рядок: \"" << str << "\"" << endl;

    // Меню вибору дії у циклі do-while з оператором switch
    do {
        showMenu();
        cout << "Ваш вибір: ";
        if (!(cin >> choice)) {
            break;
        }

        switch (choice) {
            case 1:
                cout << "-> (1) Довжина рядка (strlen): "
                     << getStringLength(str) << " символів." << endl;
                break;

            case 2:
                cout << "-> (2) Кількість слів у рядку: "
                     << countWords(str) << endl;
                break;

            case 3:
                cout << "-> (3) Кількість подвійних пробілів у рядку: "
                     << countDoubleSpaces(str) << endl;
                break;

            case 4:
                cout << "-> Повний аналіз рядка:" << endl;
                cout << "   (1) Довжина рядка:                " << getStringLength(str) << " символів" << endl;
                cout << "   (2) Кількість слів:               " << countWords(str) << endl;
                cout << "   (3) Кількість подвійних пробілів: " << countDoubleSpaces(str) << endl;
                break;

            case 0:
                cout << "Завершення роботи програми." << endl;
                break;

            default:
                cout << "Помилка: невідомий пункт меню! Спробуйте ще раз." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}

// Виведення текстового меню користувача
void showMenu()
{
    cout << "\n---------------- МЕНЮ ОПЕРАЦІЙ ----------------" << endl;
    cout << "1 - Визначити довжину рядка" << endl;
    cout << "2 - Визначити кількість слів у рядку" << endl;
    cout << "3 - Визначити кількість подвійних пробілів" << endl;
    cout << "4 - Вивести всі три показники одночасно" << endl;
    cout << "0 - Вихід" << endl;
    cout << "-----------------------------------------------" << endl;
}

// Функція (1): визначення довжини рядка за допомогою бібліотечної функції strlen()
int getStringLength(const char *s)
{
    return (int)strlen(s);
}

// Функція (2): підрахунок кількості слів у рядку з використанням isspace() з <cctype>
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

// Функція (3): підрахунок кількості подвійних пробілів ("  ") у рядку
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
