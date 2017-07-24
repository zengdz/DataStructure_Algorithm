/*
 * 题目：给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值
 */
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> res;
	if (num.empty() || size < 1)
		return res;
	deque<int> dq; // 双端队列保存的是元素的索引
	for (unsigned int i = 0; i < num.size(); ++i) {
		// 如果deque不为空且当前遍历的数大于等于队列内索引对应的数
		// 则依次把符合条件的索引从队尾弹出
		while (!dq.empty() && num[dq.back()] <= num[i])
			dq.pop_back();
		// 从后添加新的索引
		dq.push_back(i);
		// 如果队首保存的索引等于当前遍历的索引值减窗口大小
		// 说明队首的索引过期了，不再是窗口内的元素索引
		if (dq.front() == i - size)
			dq.pop_front();
		// 遍历索引达到窗口大小之后，队首保存的索引对应值就是窗口最大值
		if (i >= size - 1)
			res.push_back(num[dq.front()]);
	}
	return res;
}

int main()
{
	vector<int> num = { 2,3,4,2,6,2,5,1 };
	vector<int> res = maxInWindows(num, 3);
	for (auto i : res)
		cout << i << " ";
	cout << endl;

	return 0;
}
