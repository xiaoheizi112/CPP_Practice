#include <iostream>
using namespace std;

int main() {
    // 基本的for循环
    cout << "1-10的数字: ";
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;

    // 计算1-100的和
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    cout << "1-100的和为: " << sum << endl;

    int number[] = {1 , 2 , 3 , 4 , 5};
    for (int num : number)
    {
        cout << "num:" << num <<" ";
    }


    return 0;
}