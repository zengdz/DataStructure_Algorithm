// 河中每1米有桩，每个桩有弹簧，用数值表示可以跳的米数，为0的话陷进去
// 问N米长的河最少几步可以过河，若不能过河返回-1 
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int AcrossRiver(vector<int> &arr, int num) {
	// 如果后面代码有加减操作，不能直接赋值INT_MAX/INT_MIN，可能溢出
	// 考虑题目长度不超过10000，那么最长步数也不超过10000，赋值20000即可    
	vector<int> dp(num + 1, INT_MAX - 1);
	// dp向量含义：长度为i时需要几步可以过河 
	dp[0] = 0; // 长度为0的河不用过 
	for (int i = 1; i <= num; ++i) {
		for (int j = 0; j < i; ++j) {
			// 找前面所有可以跳的步数加其位置大于长度i可以过河的位置 
			if (arr[j] + j >= i)
				// 若赋值INT_MAX，加1之后会变成INT_MIN使得最小值为INT_MIN
				// 该位置的步数加1就是当前长度位置要走的步数，取所有满足条件的最小值 
				dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	return dp[num] == INT_MAX - 1 ? -1 : dp[num];
}


int main()
{
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i = 0; i < num; ++i)
        cin >> arr[i];
    int cnt = AcrossRiver(arr, num);
    cout << cnt << endl;
    
    return 0;
}
