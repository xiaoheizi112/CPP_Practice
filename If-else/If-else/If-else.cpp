// If-else.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
    int score;
    cout << "请输入考试成绩：（0-100）:";
    cin >> score;

    if (90 <= score && score <= 100)
    {
        cout << "优秀" << endl;
    }
    else if (80 <= score && score < 90)
    {
        cout << "良好" << endl;
    }
    else if (60 <= score && score < 80)
    {
        cout << "合格" << endl;
    }
    else if (0 <= score && score < 60)
    {
        cout << "不合格" << endl;
    }
    else
    {
        cout << "成绩无效！" << endl;
    }

    if (score >= 60)
    {
        cout << "恭喜你，考试通过！" << endl;
    }
    
    return 0;
}


