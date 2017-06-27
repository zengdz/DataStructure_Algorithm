/*
 * 这道题在查找算法二分法应用里面写过
 */
#include <iostream>
#include <vector>

using namespace std;

// 找出数据k在向量data第一次和最后一次出现的位置
// 最后一个参数为真找第一次，否则找最后一次
int FindFirstLast(vector<int> data, int k, bool First)
{
	int low = 0;
	int high = data.size() - 1;
	int res = -1;
	while (low <= high) {
		int mid = low + ((high - low) >> 1);
		if (data[mid] < k)
			low = mid + 1;
		else if (data[mid] > k)
			high = mid - 1;
		else {
			res = mid;
			if (First)
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return res;
}

int GetNumberOfK(vector<int> data, int k) 
{
	if (data.empty()) 
		return 0;
	int first = FindFirstLast(data, k, true);
	int last = FindFirstLast(data, k, false);
	if (first == -1)
		return 0;
	else
		return last - first + 1;
}


int main()
{
	vector<int> num = {1,3,4,6,8,8,8,13};
	cout << GetNumberOfK(num, 8) << endl;
	
	return 0;
}
