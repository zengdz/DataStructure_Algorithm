/*
 * 输入包含空格分割的n+1个整数，最后一个整数为k值,n不超过100。
 * 输出n个整数里最小的k个数。升序输出
 * 要求升序输出最小的K个数，只要依次输出第1最小，第2最小到第K最小
 * 示例：输入3 9 6 8 -10 7 -11 19 30 12 23 5；输出-11 -10 3 6 7
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Partition(vector<int> &A, int i, int j) {
	int key = A[i];
	while (i < j) {
		while (i < j && A[j] >= key)
			--j;
		swap(A[i], A[j]);
		while (i < j && A[i] <= key)
			++i;
		swap(A[i], A[j]);
	}
	return i;
}
int getKthNum(vector<int> A, int k) {
	int start = 0;
	int end = A.size() - 1;
	int idx = Partition(A, start, end);
	while (idx != k - 1) {
		if (idx > k - 1) {
			end = idx - 1;
			idx = Partition(A, start, end);
		}
		else {
			start = idx + 1;
			idx = Partition(A, start, end);
		}
	}
	return A[idx];
}

int main() {
	vector<int> res;
	int num;
	while (cin >> num) {
		res.push_back(num);
	}
	int k = res[res.size() - 1]; // 输入的最后一个元素是K值
	res.pop_back(); // 把K值删除
	for (int i = 1; i <= k; ++i) {
		cout << getKthNum(res, i); // 依次获取第K小的数
		if (i != k) // 输出格式最后一个输出后面不跟空格
			cout << " ";
	}
	return 0;
}
