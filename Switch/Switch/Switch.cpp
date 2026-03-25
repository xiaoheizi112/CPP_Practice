// Switch.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main() {
    int choice;
    bool running = true;
    

    while (running)
    {
        cout << "请选择：1.查询 2.存款 3.取款 4.退出" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "查询" << endl;
            break;
        case 2:
            cout << "存款" << endl;
            break;
        case 3:
            cout << "取款" << endl;
            break;
        case 4:
            cout << "退出" << endl;
            running = false;
            break;
        default:
            cout << "无效，重新选择！" << endl;
            break;
        }
    }

    
    return 0;
}


