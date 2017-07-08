/*
 * 题目：从一副牌里面随机抽5张牌，判断是否是顺子
 * 大小王可看作任意牌，为了数字化，把大小王视作0，A为1，J为11依次类推
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsContinuous(vector<int> numbers) {
	if (numbers.empty())
		return false;
	sort(numbers.begin(), numbers.end()); // 对抽到的牌进行排序
	int numOfZero = 0; // 抽到的牌中0的数量
	int numOfGap = 0; // 牌的间隔总和
	// 统计5张牌里面0的个数
	for (auto i : numbers) {
		if (i == 0)
			++numOfZero;
	}
	// 经过排序后如果存在0则都排在前面
	// 0的数量当作索引指向非0的第一个数
	int cur = numOfZero;
	int next = cur + 1;
	while (next < numbers.size()) {
		// 如果有相等的牌那么就存在对子，则顺子不存在
		if (numbers[cur] == numbers[next])
			return false;
		// 统计相邻数字之间的间隔
		numOfGap += numbers[next] - numbers[cur] - 1;
		cur = next; // 更新索引
		++next;
	}
	// 如果间隔数大于0的数量则不为顺子
	// 否则要么本来就是顺子，要么可以用0来填补
	return (numOfGap > numOfZero) ? false : true;
}

int main()
{
	vector<int> cards1 = { 1,3,4,5,0 }; // 顺子
	vector<int> cards2 = { 1,3,4,6,0 }; // 不是顺子
	vector<int> cards3 = { 1,3,3,6,0 }; // 存在对子，不是顺子
	cout << IsContinuous(cards1) << endl;
	cout << IsContinuous(cards2) << endl;
	cout << IsContinuous(cards3) << endl;

	return 0;
}
