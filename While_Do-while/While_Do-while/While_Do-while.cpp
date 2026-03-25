#include <iostream>
using namespace std;

int main() {
    // while循环示例
    int count = 1;
    cout << "while循环输出: ";
    while (count <= 5) {
        cout << count << " ";
        count++;
    }
    cout << endl;

    // do-while循环示例
    int number;
    do {
        cout << "请输入一个正数: ";
        cin >> number;
    } while (number <= 0);

    cout << "你输入的正数是: " << number << endl;

    return 0;
}