#include <iostream>
#include <string>
#include "StudentManager.h"
using namespace std;

// 构造函数实现
StudentManager::StudentManager() : count(0) {
    // 初始化数组（可选）
    for (int i = 0; i < 10; i++) {
        students[i] = "";
        scores[i] = 0;
    }
}

// 添加学生实现
void StudentManager::addStudent(string name, int score) {
    if (count < 10) {
        students[count] = name;
        scores[count] = score;
        count++;
        cout << "成功添加学生: " << name << endl;
    }
    else {
        cout << "学生数量已达上限!" << endl;
    }
}

// 显示所有学生
void StudentManager::showAllStudents() {
    cout << "所有学生信息:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "  " << students[i] << " - 成绩: " << scores[i];
        if (scores[i] >= 90) {
            cout << " (优秀)";
        }
        cout << endl;
    }
}

// 计算平均分
void StudentManager::showAverage() {
    if (count == 0) {
        cout << "没有学生数据!" << endl;
        return;
    }

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += scores[i];
    }
    double average = static_cast<double>(total) / count;
    cout << "班级平均分: " << average << endl;
}

