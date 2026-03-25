#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>

using namespace std;

class String {
private:
    char* data;
    size_t length;

public:
    // 普通构造函数
    String(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    // 拷贝构造函数
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
        std::cout << "Copy constructor called" << std::endl;
    }

    // 析构函数
    ~String() {
        delete[] data;
    }

    // 显示内容
    void display() const {
        std::cout << data << std::endl;
    }
};

// 使用示例
void processString(String s) {
    s.display();
}

int main() {
    String str1("Hello");
    String str2 = str1;      // 调用拷贝构造函数
    String str3(str1);       // 调用拷贝构造函数
    processString(str1);     // 调用拷贝构造函数（值传递）
    return 0;
}