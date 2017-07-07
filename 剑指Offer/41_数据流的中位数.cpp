/*
 * 题目：得到一个数据流中的中位数，数量为奇数则中位数为中间数否则就是中间两个数的均值
 * 方法一：简单直接的就是每次插入数据都进行排序，然后取中间的数作为中位数
 * 方法二：维护两个堆，中位数就是左边的最大值右边的最小值
 */
#include <iostream>
#include <vector>
#include <functional> // greater
#include <queue>

using namespace std;

class Solution {
	priority_queue<int, vector<int>, less<int>> p; // 左边大顶堆
	priority_queue<int, vector<int>, greater<int>> q; // 右边小顶堆
public:
	void Insert(int num)
	{
		// 如果左边为空或者数据小于左边最大值
		if (p.empty() || num < p.top())
			p.push(num);
		else
			q.push(num);
		// 左边要么比右边多1个数据，要么两边相等
		// 如果数据个数违反上面的，则要调整两边数据
		if (p.size() == q.size() + 2) {
			q.push(p.top());
			p.pop();
		}
		else if (q.size() == p.size() + 1) {
			p.push(q.top());
			q.pop();
		}
	}

	double GetMedian()
	{
		// 如果两边数量相等，则中位数是两边队首的均值
		if (p.size() == q.size())
			return (p.top() + q.top()) / 2.0;
		// 若不相等则左边多1个，中位数就是左边的队首
		else
			return p.top();
	}
};

int main()
{

	return 0;
}
