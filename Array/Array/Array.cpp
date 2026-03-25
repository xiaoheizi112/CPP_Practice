#include <iostream>
using namespace std;

int main() {
    int scores[5]{ 85,67,42,53,78 };

    // 访问数组元素
    cout << "第一个学生成绩: " << scores[0] << endl;
    cout << "最后一个学生成绩: " << scores[4] << endl;

    // 遍历数组
    cout << "所有成绩: ";
    for (int sco:scores) {
        cout << sco << " ";
    }
    cout << endl;

    // 计算平均分
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += scores[i];
    }
    double average = static_cast<double>(total) / 5;
    cout << "平均成绩: " << average << endl;

    // C++11的数组初始化
    double temperatures[]{ 25.5, 26.0, 24.8, 27.2, 23.9 };

    return 0;
}