#include <iostream>
using namespace std; // std:: is required for cout, cin, endl, string, etc.

// Function overloading example
// Same function name with different parameter types

// C언어 에서는, 함수 호출시, 함수 이름만 찾는 반면, C++에서는, 함수 이름과 매개변수의 타입을 함께 고려하여,
// 어떤 함수를 호출할지 결정합니다.

int add(int a, int b) {
    cout << "Adding two integers: " << a << " + " << b << " = ";
    return a + b;
}

double add(double a, double b) {
    cout << "Adding two doubles: " << a << " + " << b << " = ";
    return a + b;
}

int add(int a, int b, int c) {
    cout << "Adding three integers: " << a << " + " << b << " + " << c << " = ";
    return a + b + c;
}

void display(int x) {
    cout << "Integer: " << x << endl;
}

void display(double x) {
    cout << "Double: " << x << endl;
}

void display(string s) {
    cout << "String: " << s << endl;
}

void DefaultValueExample(int a, int b = 10) {
    // 값이 넘어오지 않으면, b는 10으로 초기화됩니다.
    cout << "a: " << a << ", b: " << b << ", sum: " << (a + b) << endl;
}

int main() {
    cout << "=== Function Overloading Example ===" << endl << endl;

    // Calling overloaded add functions
    cout << add(5, 10) << endl;
    cout << add(3.5, 2.5) << endl;
    cout << add(1, 2, 3) << endl;

    cout << endl << "=== Display Overloading ===" << endl;
    display(42);
    display(3.14);
    display("Hello Overloading");

    DefaultValueExample(0,11);

    return 0;
}
