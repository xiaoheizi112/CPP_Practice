// 通过引用参数返回计算结果
void calculateStats(const vector<int>& numbers,
    double& average,
    int& max,
    int& min) {
    if (numbers.empty()) return;

    double sum = 0;
    max = numbers[0];
    min = numbers[0];

    for (int num : numbers) {
        sum += num;
        if (num > max) max = num;
        if (num < min) min = num;
    }

    average = sum / numbers.size();
}

void multipleReturnDemo() {
    vector<int> scores = { 85, 92, 78, 96, 88 };
    double avg;
    int highest, lowest;

    calculateStats(scores, avg, highest, lowest);

    cout << "平均分: " << avg << endl;
    cout << "最高分: " << highest << endl;
    cout << "最低分: " << lowest << endl;
}