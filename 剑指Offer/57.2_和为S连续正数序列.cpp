/*
 * 题目：输入一个正数S，打印所有和为S的连续正数序列（至少2个数）
 * 思路：两个索引begin和end用于表示连续区间[begin,end]
 * 首先将begin初始化为1，end初始化为2，如果区间和大于sum，增大begin,否则增大end。
 * 循环条件为：begin小于(1+sum)/2
 */
#include <iostream>
#include <vector>

using namespace std; 

void InsertResult(vector<vector<int>> &res, int begin, int end)
{
    vector<int> temp;
    for(int i = begin; i <= end; ++i)
        temp.push_back(i);
    res.push_back(temp);
}

vector<vector<int>> FindContinuousSequence(int sum)
{
    vector<vector<int>> res;
	// 因为至少2个数，最小为1+2=3所以不能小于3
    if(sum < 3) 
		return res;
	// 至少两个数,计算上限值begin+(begin+1)=sum，得到begin=(sum-1)/2
	// 取开区间的话，在上面的结果加1得到 (sum+1)/2
    int mid = (sum + 1) / 2;
    int begin = 1;
    int end = 2;
    int cur_sum = begin + end;
	// 不加&&end<sum条件也能通过nowcode的测试
    while(begin < mid){
		// 如果偏大，需要减小左边的值并更新左区间
		if(cur_sum > sum) {
			cur_sum -= begin;
			++begin; // 减小是减掉已有的，索引更新在后面
		}
		// 如果偏小，需要增大右边并更新右区间
		else if(cur_sum < sum){
			++end; // 增大时增加新的，索引更新在前面
			cur_sum += end;
		}
		// else-if和else可以合并，为了方便理解没有合并
		// 如果找到相等则添加到向量，继续右边扩大找其他序列
		else {
			InsertResult(res, begin, end);
			++end;
			cur_sum += end;
		}
    }
    return res;
}

int main()
{
	// 15 = 1+2+3+4+5 = 4+5+6 = 7+8
	vector<vector<int>> res = FindContinuousSequence(15);

	// 输出二维向量 
	for(auto i = 0; i != res.size(); ++i){
		for(auto j = 0; j != res[i].size(); ++j){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
