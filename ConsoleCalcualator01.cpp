#include <iostream>
#include <print>
#include <clocale>
#include <numbers>
using namespace std;

void errorMessage(const string& message);
double compute(double a, double b, const string& op);
double factorial(int a);
double sinOfDegrees(double a);

int main() {
    setlocale(LC_ALL, "ru");

    double a = 0;
    double b = 0;
    double result = 0;

    std::print("Введи первое число: ");
    if (!(cin >> a)) {
        errorMessage("Ошибка: введено не число");
        return 1;
    }

    std::string op;
    std::string allowed[] = { "+", "-", "*", "/", "^", "!", "sin"};

    std::print("Введи операцию (+ - * / ^ ! sin): ");
    cin >> op;

    if (std::find(std::begin(allowed), std::end(allowed), op)
        == std::end(allowed)) {
        errorMessage("Ошибка: неизвестная операция");
        return 1;
    }

    if (op == "!") {
        result = factorial((int)a);
    }
    else if (op == "sin") {
        result = sinOfDegrees(a);
    }
    else {
        std::print("Введи второе число: ");
        if (!(cin >> b)) {
            errorMessage("Ошибка: введено не число");
            return 1;
        }
        result = compute(a, b, op);
    }

    if (std::isnan(result)) {
        std::println("Результат некорректен");
    }
    else {
        result = std::round(result * 1000.0) / 1000.0;
        if (op == "!") {
            std::println("{}{} = {}", a, op, result);
        }
        else if (op == "sin") {
            std::println("{}({}) = {}", op, a, result);
        }
        else {
            std::println("{} {} {} = {}", a, op, b, result);
        }
    }

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

double compute(double a, double b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return (b != 0) ? a / b : std::nan("");
    if (op == "^") return std::pow(a,b);

    return std::nan(""); // неизвестная операция
}

double factorial(int n) {
    if (n < 0) return std::nan("");
    double res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

double sinOfDegrees(double degrees) {
    return std::sin(degrees * std::numbers::pi / 180.0);
}
