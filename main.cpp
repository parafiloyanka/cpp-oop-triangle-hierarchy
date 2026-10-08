#include <iostream>
#include "Triangle.h"

using namespace std;

void welcome() {
    cout << "\033[1;35m"
         << "Лабораторна робота 6. Дослідження особливостей реалізації принципів ООП.\n"
         << "\033[1;36m"
         << "Завдання 1. Ієрархія класів (Triad -> Triangle)\n"
         << "\033[1;35m"
         << "Алєксєєва Аліна КБ-21. Варіант 1\n"
         << "\033[0m\n";
}

int main() {
    welcome();

    while (true) {
        double a, b, c;
        do {
            cout << "Введіть три сторони трикутника (a, b, c): ";
            cin >> a >> b >> c;

            if (cin.fail() || a <= 0 || b <= 0 || c <= 0) {
                cout << "\033[1;31m Некоректні дані!\033[0m\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                Triangle t(a, b, c);
                if (t.isValid()) {
                    t.printTriangle();
                    break;
                } else {
                    t.printTriangle();
                    cout << "\033[1;34m Бажаєте автоматично виправити сторони? \033[0m: ";
                    int fixChoice;
                    cin >> fixChoice;
                    if (fixChoice == 1) {
                        // Автоматично встановлюємо найближчий можливий трикутник
                        if (a + b <= c) c = a + b - 0.01;
                        if (a + c <= b) b = a + c - 0.01;
                        if (b + c <= a) a = b + c - 0.01;
                        Triangle fixedT(a, b, c);
                        fixedT.printTriangle();
                        break;
                    }
                }
            }
        } while (true);

        int choice;
        cout << "\nНатисніть 1, щоб продовжити, або іншу клавішу для виходу: ";
        cin >> choice;
        if (choice != 1) {
            cout << "\033[1;35m" << "Дякую за використання програми!\n\t Алєксєєва Аліна КБ-21\n"<< "\033[0m";
            break;
        }
    }
        return 0;
}