#include <iostream>
using namespace std;

// 函数声明（原型）
int add(int a, int b);
void printMessage(string message);
double calculateCircleArea(double radius);

int main() {
    // 函数调用
    int result = add(15, 27);
    cout << "15 + 27 = " << result << endl;

    printMessage("Hello, Function!");

    double area = calculateCircleArea(5.0);
    cout << "半径为5的圆面积: " << area << endl;

    return 0;
}

// 函数定义 - 加法函数
int add(int a, int b) {
    return a + b;
}

// 函数定义 - 打印消息（无返回值）
void printMessage(string message) {
    cout << "消息: " << message << endl;
}

// 函数定义 - 计算圆面积
double calculateCircleArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}