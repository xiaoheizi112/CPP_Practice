// Operator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
    int a = 10, b = 5;
    cout << "a+b = " << (a + b) << endl;
    cout << "a-b = " << (a - b) << endl;
    cout << "a*b = " << (a * b) << endl;
    cout << "a/b = " << (a / b) << endl;
    cout << "a%b = " << (a % b) << endl;

    cout << "a > b: " << (a > b) << endl;
    cout << "a == b: " << (a == b) << endl;

    bool x = true, y = false;
    cout << "x && y: " << (x && y) << endl;  
    cout << "x || y: " << (x || y) << endl;  
    cout << "!x: " << (!x) << endl;          

    a += 5;  
    cout << "a += 5 后: " << a << endl;
    return 0;
}

