#include <iostream>

using namespace std;
int main() 
{
	int age = 23;
	double height = 1.7;
	char initial = 'A';
	bool isStudent = true;
	string name = "zhangsan";

	int score{ 95 };
	double tempereture = { 36.5 };

	const double PI = 3.141592;
	const int MAX_SIZE{ 100 };

	cout << "age = " << age << endl;
	cout << "height = " << height << endl;
	cout << "initial = " << initial << endl;
	cout << "isStudent = " << isStudent << endl;
	cout << "name = " << name << endl;
	return 0;
}