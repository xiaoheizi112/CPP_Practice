#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <iostream>
#include <string>
using namespace std;

class StudentManager {
private:
    string students[10];
    int scores[10];
    int count{ 0 };

public:
    // 构造函数
    StudentManager();

    // 添加学生
    void addStudent(string name, int score);

    // 显示所有学生
    void showAllStudents();

    // 计算平均分
    void showAverage();
};

#endif

