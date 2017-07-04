/*
 * 题目：把一个正整数数组所有数字拼成一个数，输出所有拼接数中最小的一个
 * 注意拼接起来可能溢出，通过把数字转换为字符串进行处理使用to_string函数
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 如果是类的成员函数，需要给compare添加static 
// 因为sort函数是全局的，无法在sort中调用非静态成员函数
bool compare(int a, int b)
{
	string A, B;
	A += to_string(a);
	A += to_string(b);
	B += to_string(b);
	B += to_string(a);
	return A < B;
}

string PrintMinNumber(vector<int> numbers)
{
	string res;
	if (numbers.empty())
		return res;
	// 按照compare规则比较排序
	sort(numbers.begin(), numbers.end(), compare);
	// 把排好序的数组依次拼接就是结果
	for (auto i : numbers)
		res += to_string(i);
	return res;
}

int main()
{
	vector<int> numbers = { 3,32,321 };
	cout << PrintMinNumber(numbers) << endl;

	return 0;
}
