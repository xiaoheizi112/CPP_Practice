// 返回引用 - 必须确保返回的对象仍然存在
int& getElement(vector<int>& vec, int index) {
    return vec[index];  // 返回引用，可以修改原vector
}

// 危险示例：返回局部变量的引用
int& dangerousFunction() {
    int localVar = 42;
    return localVar;  // 错误！局部变量将在函数结束时销毁
}

void referenceReturnDemo() {
    vector<int> numbers = { 10, 20, 30, 40, 50 };

    // 通过返回的引用修改原数据，将30改为999
    getElement(numbers, 2) = 999;

    cout << "修改后的vector: ";
    for (int num : numbers) {
        cout << num << " ";  // 输出: 10 20 999 40 50
    }
    cout << endl;
}