/*
 * 题目：找出n个整数中最小的K个数
 * 方法一：先排序然后取前K个数。缺点：修改原数据，如果数据量大无法一次载入进行排序
 * 方法二：K个数的容器，每次从原数据取数比较判断是否在容器插入或者删除，无方法一的缺点
 */
#include <iostream>
#include <vector>
#include <set> // multiset
#include <functional> // greater
#include <string>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	if (input.size() < k || k < 1)
		return vector<int>(); // 返回一个空的向量
	// 使用STL中的multiset并且使用greater从大到小排序
	// 容器的第一个元素就是最大值
	multiset<int, greater<int>> leastNumber;
	multiset<int, greater<int> >::iterator iter;
	for (auto i : input) {
		// 如果容器没有满，则插入新的数据
		if (leastNumber.size() < k)
			leastNumber.insert(i);
		// 否则把当前遍历数据和容器最大值比较
		// 如果当前数据更小则把容器最大值删除并插入当前值
		else {
			iter = leastNumber.begin();
			if (i < *iter) {
				leastNumber.erase(*iter);
				leastNumber.insert(i);
			}
		}
	}
	// 使用容器的迭代器构造向量进行返回
	return vector<int>(leastNumber.begin(), leastNumber.end());
}

// 使用string类传递输出信息
// 因为向量是迭代的，使用for范围语句遍历元素
void PrintVector(const string info, const vector<int>& arr)
{
	cout << info;
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
}

int main()
{
	vector<int> numbers = { 4,5,1,6,2,7,3,8 };
	vector<int> res = GetLeastNumbers_Solution(numbers, 4);
	PrintVector("Least 4 numbers are: ", res);

	return 0;
}
