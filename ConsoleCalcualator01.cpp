#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int a, b;
    cout << "Введи первое число: ";
    cin >> a;
    cout << "Введи второе число: ";
    cin >> b;
    cout << "Сумма: " << a + b << endl;

    cin.get(); // чтобы поймать Enter после второго числа
    cin.get(); // ожидание ввода
    return 0;
}
