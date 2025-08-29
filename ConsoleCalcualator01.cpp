#include <iostream>
#include <print>
#include <clocale>
using namespace std;

void errorMessage(const string& message);
double compute(double a, double b, const string& op);

int main() {
    setlocale(LC_ALL, "ru");

    std::print("Введи первое число: ");
    double a;
    if (!(cin >> a)) {
        errorMessage("Ошибка: введено не число");
        return 1;
    }

    std::string op;
    std::string allowed[] = { "+", "-", "*", "/" };

    std::print("Введи операцию (+ - * /): ");
    cin >> op;

    if (std::find(std::begin(allowed), std::end(allowed), op)
        == std::end(allowed)) {
        errorMessage("Ошибка: неизвестная операция");
        return 1;
    }

    std::print("Введи второе число: ");
    double b;
    if (!(cin >> b)) {
        errorMessage("Ошибка: введено не число");
        return 1;
    }
    cin.get();

    double result = compute(a, b, op);

    if (std::isnan(result)) {
        std::println("Результат некорректен");
    }
    else {
        std::println("{} + {} = {}", a, b, result);
    }

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

double compute(double a, double b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return (b != 0) ? a / b : std::nan("");

    return std::nan(""); // неизвестная операция
}