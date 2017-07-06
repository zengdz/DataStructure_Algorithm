/*
 * 题目：数组中的两个数字，若前面数字大于后面数字，则组成一个逆序对
 * 给定一个数组，求出其中所有逆序对的总数
 */
#include <iostream>
#include <vector>

using namespace std;

int InversePair_MergeSort(vector<int> &data, int start, int end)
{
	if (start == end)
		return 0;
	int mid = start + ((end - start) >> 1);
	int LeftCnt = InversePair_MergeSort(data, start, mid);
	int RightCnt = InversePair_MergeSort(data, mid + 1, end);

	vector<int> temp(data);
	int FrontHalfIdx = mid;
	int BackHalfIdx = end;
	int TempIdx = end;
	int cnt = 0;
	while (FrontHalfIdx >= start && BackHalfIdx >= mid + 1) {
		if (data[FrontHalfIdx] > data[BackHalfIdx]) {
			temp[TempIdx--] = data[FrontHalfIdx--];
			cnt += BackHalfIdx - mid;
		}
		else
			temp[TempIdx--] = data[BackHalfIdx--];
	}
	while (FrontHalfIdx >= start)
		temp[TempIdx--] = data[FrontHalfIdx--];
	while (BackHalfIdx >= mid + 1)
		temp[TempIdx--] = data[BackHalfIdx--];
	// 如果数据量很大，每次的赋值会消耗很多时间
	// 剑指Offer上有个技巧：把辅助向量加入形参，然后递归时交换辅助向量和原向量
	for (int i = start; i <= end; i++)
		data[i] = temp[i];
	return (LeftCnt + RightCnt + cnt);
}

int InversePairs(vector<int> data)
{
	if (data.empty())
		return 0;
	return InversePair_MergeSort(data, 0, data.size() - 1);
}

int main()
{
	vector<int> data = {7,5,6,4};
	cout << InversePairs(data) << endl;

	return 0;
}
