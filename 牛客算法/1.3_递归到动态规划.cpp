/*
 * 题目：有一排正数，玩家A和玩家B都可以看到。
 * 每位玩家在拿走数字的时候，都只能从最左和最右的数中选择一个。
 * 玩家A先拿，玩家B再拿，两人交替拿走所有的数字，
 * 两人都力争自己拿到的数的总和比对方多。请返回最后获胜者的分数
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 只考虑先拿的人的情况
int f(vector<int> &arr, int i, int j)
{
	// 如果只剩一个，作为先拿的人，就会拿掉这个
	if (i == j)
		return arr[i];
	// 如果还剩两个，先拿的人会拿掉大的那个
	if (i + 1 == j)
		return max(arr[i], arr[j]);
	// 先拿两边的任一个，后拿的人只有拿的较小才能使先拿的得到最多
	// 两个人都是理性的，先拿的max后拿的min就能保持这种规则
	return max(arr[i] + min(f(arr, i + 2, j), f(arr, i + 1, j - 1)),
		arr[j] + min(f(arr, i + 1, j - 1), f(arr, i, j - 2)));
}
// 方案一：递归
int win1(vector<int> arr)
{
	if (arr.empty() || arr.size() < 1)
		return 0;
	int first = f(arr, 0, arr.size() - 1);
	int sum = 0;
	for (auto i : arr)
		sum += i;
	// 要么先拿的人最多，要么另一个人最多
	// 先拿不一定就最多，但赢得概率更大
	// 零和博弈，不是你多就是我多，双方都会挑大的拿
	return max(first, sum - first);
}

// 方案二：动态规划
int win2(vector<int> arr)
{
	if (arr.empty() || arr.size() < 1)
		return 0;
	if (arr.size() == 1)
		return arr[0];
	if (arr.size() == 2)
		return max(arr[0], arr[1]);
	int sum = 0;
	for (auto i : arr)
		sum += i;
	int length = arr.size();
	// dp的下标就是i和j的变化，二维向量的值就是不同i,j组合时的结果
	// 注意vector的二维向量的初始化形式
	vector<vector<int>> dp(length, vector<int>(length));
	// 根据已知的信息给dp赋值，由这些已知可以推导其他情况
	// 把已知值画出来，就是正方形对角线的两条线
	// 因为i+1最大为arr大小，从0计数，所以小于arr.size()-1
	// 为什么要有两组初值，因为从递归能看出需要两组状态才能推导
	for (int i = 0; i < length - 1; ++i) {
		// 当i=j时，只有一个元素，结果就是该元素
		dp[i][i] = arr[i];
		// 当i+1=j时，有两个元素，结果是较大的那个
		dp[i][i + 1] = max(arr[i], arr[i + 1]);
	}
	// 接下来把dp表的其他值(其实是左上三角)计算出来
	// 这里循环变量k,i,j也不易理解：y=x+k,k是平移量，区间[2,length-1]
	for (int k = 2; k < length; ++k) {
		for (int j = k; j < length; ++j) {
			int i = j - k;
			dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
				arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
		}
	}
	return max(dp[0][length - 1], sum - dp[0][length - 1]);
}

int main()
{
	// 如果先拿：5,3得到8；如果后拿：4,2得到6
	// 因为不是先拿的人就一定最多，比如有三个数{1,300,1}无论先拿的人拿哪个，后拿的却更多
	// 所以要看两种情况的最大值，最大的那个和是8
	vector<int> arr  = {5,2,3,4};
	cout << win2(arr) << endl;
	return 0;
}
