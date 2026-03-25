#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int>nums = { 3,5,6,8,9,2,4 };

	//lambda用于排序
	//sort(起始位置, 结束位置, 比较函数/Lambda);
	sort(nums.begin(), nums.end(), [](int a, int b) {
		return a < b;
		});
	for (int num : nums) 
	{
		cout << num << " " ;
	}
	cout << endl;

	//Lambda捕获列表
	int minVal = 2;
	int maxVal = 5;
	// 按值捕获 minVal 和 maxVal
	auto isInRange = [minVal, maxVal](int x) -> bool {
		return x >= minVal && x <= maxVal;
		};
	//满足范围内的数组个数有多少
	auto count = std::count_if(nums.begin(), nums.end(), isInRange);
	std::cout << "Numbers in range: " << count << std::endl;

	//Lambda按值捕获并修改
	int counter = 0;
	// 按值捕获 counter，并使用 mutable 来修改它
	auto incrementer = [counter]() mutable {
		counter++;
		std::cout << "Internal counter: " << counter << std::endl;
		};

	//引用捕获
	int externalVal = 10;
	auto refCapturer = [&externalVal]() {
		externalVal *= 2; // 修改外部变量
		};
	refCapturer();
	std::cout << "externalVal: " << externalVal << std::endl; // 输出：externalVal: 20
	return 0;
}