/*
 * 一个全是正数的数组，能否将其分为四部分，每部分的和相等，分割值不算。
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool canSplit(vector<int> array){
	// 如果为空或者数量少于7返回假，因为至少要7个元素才能分四部分
	if (array.empty() || array.size() < 7)
		return false;
	int length = array.size();
	int allSum = array[0];
	map<int, int> map; // value代表下标[1,length-2],key为0到下标减1区间的和
	for (int i = 1; i < length; ++i) {
		map[allSum] = i; // 因为全是正数，key值不会重复
		allSum += array[i]; // 经常误把元素值写成索引！
	}
	int lsum = array[0];
	// s1就是在遍历第一个分割点
	// s1后面至少还有5个元素才能分割成4部分，注意结束下标
	for (int s1 = 1; s1 < length - 5; ++s1) {
		int checkSum = 2 * lsum + array[s1]; // 从0到第二个分割点的总和
		if (map.count(checkSum)) { // 是否存在第二个分割点
			int s2 = map[checkSum];
			checkSum += lsum + array[s2]; // 从0到第三个分割点的总和
			if (map.count(checkSum)) {// 是否存在第三个分割点
				int s3 = map[checkSum];
				if (checkSum + array[s3] + lsum == allSum) // 第四个分割点是否存在
					return true;
			}
		}
		lsum += array[s1]; // 更新第一个分割点的累加和
	}
	return false;
}

int main()
{
	vector<int> arr1 = { 3,4,2,7,3,6,1,1,7 }; // 可以分割4部分，每部分和为7
	vector<int> arr2 = { 3,4,2,7 }; // 不可以分割4部分，数量太少
	vector<int> arr3 = { 1,2,3,4,5,6,7 }; // 不可以分割4部分
	cout << canSplit(arr1) << endl;
	cout << canSplit(arr2) << endl;
	cout << canSplit(arr3) << endl;

	return 0;
}
