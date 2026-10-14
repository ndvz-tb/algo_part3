#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    // Варіант 2 (для варіанта 17 у списку групи):
    // Обчисліть площу квадрата S = a^2
    double a, S;

    cout << "Input side of square (a):\n";
    cin >> a;

    S = a * a;

    cout << "Side a = " << a << endl;
    cout << "Square Area S = " << S << "\n\n";

    system("pause");
    return 0;
}
