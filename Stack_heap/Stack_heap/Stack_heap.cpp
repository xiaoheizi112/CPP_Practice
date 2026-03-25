#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    std::string name;
    int age;
public:
    Student(const string& n, int a) : name(n), age(a) {
        std::cout << "构造 Student: " << name << std::endl;
    }
    ~Student() {
        std::cout << "析构 Student: " << name << std::endl;
    }
    void display() const {
        std::cout << "姓名: " << name << ", 年龄: " << age << std::endl;
    }
};

void memoryDemo() {
    std::cout << "=== 函数开始 ===" << std::endl;

    // 栈上的对象 - 自动管理
    Student stack_student("张三", 20);
    stack_student.display();

    // 堆上的对象 - 手动管理
    Student* heap_student = new Student("李四", 22);
    heap_student->display();

    // 数组示例
    int stack_array[5] = { 1, 2, 3, 4, 5 }; // 栈上数组
    int* heap_array = new int[100];        // 堆上数组

    std::cout << "=== 函数结束前 ===" << std::endl;

    // 必须手动释放堆内存
    delete heap_student;
    delete[] heap_array;

    // stack_student 会自动析构
    // stack_array 会自动释放
}

int main() {
    memoryDemo();
    std::cout << "=== main函数结束 ===" << std::endl;
    return 0;
}