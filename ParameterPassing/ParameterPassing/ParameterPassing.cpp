#include <iostream>
using namespace std;

class TestObject {
public:
    int data;
    TestObject(int d) : data(d) {
        cout << "构造函数调用" << endl;
    }
    TestObject(const TestObject& other) : data(other.data) {
        cout << "拷贝构造函数调用" << endl;
    }
};

void comparePassMethods() {
    cout << "=== 参数传递方式对比 ===" << endl;

    TestObject obj(100);

    // 值传递：调用拷贝构造函数，创建完整副本
    auto byValue = [](TestObject o) {
        cout << "值传递 - 对象数据: " << o.data << endl;
        };

    // 引用传递：不创建副本，直接操作原对象
    auto byReference = [](TestObject& o) {
        cout << "引用传递 - 对象数据: " << o.data << endl;
        };

    // 指针传递：传递地址，不创建对象副本
    auto byPointer = [](TestObject* o) {
        cout << "指针传递 - 对象数据: " << o->data << endl;
        };

    cout << "值传递测试:" << endl;
    byValue(obj);

    cout << "引用传递测试:" << endl;
    byReference(obj);

    cout << "指针传递测试:" << endl;
    byPointer(&obj);
}

int main()
{
    comparePassMethods();
    return 0;
}