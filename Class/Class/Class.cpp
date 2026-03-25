#include <iostream>
#include <string>
using namespace std;

// 学生类的定义
class Student {
private:
    string name;        // 私有数据成员
    int age;
    double score;

public:
    // 构造函数 - 用于初始化对象
    Student(string n, int a, double s) {
        this->name = n;
        this->age = a;
        this->score = s;
    }

    // 成员函数 - 显示学生信息
    void displayInfo() {
        cout << "学生信息:" << endl;
        cout << "  姓名: " << name << endl;
        cout << "  年龄: " << age << endl;
        cout << "  成绩: " << score << endl;
    }

    // 设置器函数 - 设置成绩
    void setScore(double s) {
        if (s >= 0 && s <= 100) {
            score = s;
        }
    }

    // 获取器函数 - 获取成绩
    double getScore() {
        return score;
    }

    // 判断是否优秀
    bool isExcellent() {
        return score >= 90;
    }
};

int main() {
    // 创建学生对象
    Student student1("张三", 20, 92.5);
    Student student2("李四", 19, 85.0);

    // 调用成员函数
    student1.displayInfo();
    student2.displayInfo();

    // 使用设置器和获取器
    student2.setScore(95.0);
    cout << "李四修改后的成绩: " << student2.getScore() << endl;

    // 判断学生是否优秀
    if (student1.isExcellent()) {
        cout << "张三是优秀学生!" << endl;
    }

    return 0;
}