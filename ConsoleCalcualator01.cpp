#include <iostream>
#include <print>
#include <clocale>
using namespace std;

void errorMessage(const string& message);

int main() {
    setlocale(LC_ALL, "ru");

    std::print("Введи первое число: ");
    double a;
    if (!(cin >> a)) {
        errorMessage("Ошибка: введено не число");
        return 1;
    }

    std::print("Введи второе число: ");
    double b;
    if (!(cin >> b)) {
        errorMessage("Ошибка: введено не число");
        return 1;
    }

    std::println("{} + {} = {}", a, b, a + b);

    cin.get();
    cin.get();
    return 0;
}

void errorMessage(const string& message)
{
    std::println("{}", message);
    cin.clear();
    cin.ignore(1000, '\n');
    cin.get();
}

