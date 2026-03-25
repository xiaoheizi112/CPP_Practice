#include <memory>
#include <iostream>
using namespace std;

class MyClass {
private:
	int data;
public:
	MyClass(int value) :data(value) {
		cout << "MyClass constructed: " << data << endl;
	}
	~MyClass() {
		cout << "MyClass destroyed: " << data << endl;
	}

	void doSomething() {
		cout << "Doing something with: " << data << endl;
	}
};
int main()
{
	auto ptr = make_unique<MyClass>(20);
	auto ptr2 = make_unique<MyClass>(20);

	ptr->doSomething();

	unique_ptr<MyClass> ptr3 = move(ptr);
	if (!ptr) {
		cout << "ptr 现在为空了" << endl;
	}

	ptr2.reset();

	MyClass* rawPtr = ptr3.release(); // 交出所有权，不销毁对象
	delete rawPtr;//必须手动销毁
	return 0;
}