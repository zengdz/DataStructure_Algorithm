/*
 * 给定一个矩阵，其中有很多的子矩阵，计算子矩阵的最大和
 */
#include <vector>
#include <algorithm>
#include <limits.h> // INT_MIN
#include <iostream>

using namespace std;

// 算法原型：在数组中找子数组最大和
int SubArrayMaxSum(vector<int> &array) {
	if (array.empty())
		return 0;
	int res = array[0];
	int cur = array[0];
	// 第一个元素已经统计，遍历时下标从1而不是从0开始
	for (int i = 1; i < array.size(); ++i) {
		// 如果当前和小于0则清零，否则不变
		cur = cur < 0 ? 0 : cur;
		cur += array[i]; // 累加遍历元素值
		res = max(cur, res); // 更新最大值
	}
	return res;
}

// 在子矩阵中找最大和需要考虑很多行数组的情况
// 对于N*N矩阵，复杂度为O(n^3)
// 如果是M*N矩阵，复杂度为O(m^2*n)，如果M>>N，则可把矩阵转置使复杂度降为O(n^2*m)
int SubMatrixMaxSum(vector<vector<int> > mat, int n) {
	if (mat.empty() || n < 1)
		return 0;
	int maxSum = INT_MIN;
	for (int i = 0; i < mat.size(); ++i) { // 以第几行开始
		vector<int> s(mat[0].size(), 0); // 初始化为0
		for (int j = i; j < s.size(); ++j) {
			for (int k = 0; k < s.size(); ++k) {
				s[k] += mat[j][k]; // 循环叠加多行元素
			}
			maxSum = max(maxSum, SubArrayMaxSum(s)); // 计算不同行组合的最大和
		}
	}
	return maxSum;
}

int main()
{
	vector<vector<int>> matrix = { {2,3,4},{-4,5,-7}, {3,7,1} };
	cout << SubMatrixMaxSum(matrix, 3) << endl;

	return 0;
}
