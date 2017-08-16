/*
 * 总结Top-K问题以及partition的应用
 * 第K小的数就是第n-K+1大的数，可以转换
 * 直观的方法就是排序然后取对应位置的值；
 * 若要求O(n)考虑partition方法，若严格要求O(n)考虑bfprt算法；
 * 若要求处理大数据，则用堆排序思路，复杂度O(nlogn)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

// 一个无序数组，数组中元素为互不相同的整数，请返回其中最小的k个数，顺序与原数组中元素顺序一致
// 注意返回数的顺序不变，所以不能在排序后的数组中处理
// 找到第K小的数之后，在原数组依次遍历找小于等于该第K小数，能够保证顺序一致
class KthNumbers {
    int Partition(vector<int> &A, int i, int j){
        int key = A[i];
        while(i < j){
            while(i < j && A[j] >= key)
                --j;
            swap(A[i], A[j]);
            while(i < j && A[i] <= key)
                ++i;
            swap(A[i], A[j]);
        }
        return i;
    }
    int getKthNum(vector<int> A, int k){
        int start = 0;
        int end = A.size() - 1;
        int idx = Partition(A, start, end);
        while(idx != k - 1){
            if(idx > k - 1){
                end = idx - 1;
                idx = Partition(A, start, end);
            } else{
                start = idx + 1;
                idx = Partition(A, start, end);
            }
        }
        return A[idx];
    }
public:
    vector<int> findKthNumbers(vector<int> A, int n, int k) {
        vector<int> res;
        if(A.empty() || n < 1 || k < 1)
            return res;
        int kNum = getKthNum(A, k);
        for(auto i : A){
            if(i <= kNum)
                res.push_back(i);
        }
        return res;
    }
};

// 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
// 注意数字可能重复，以及需要额外的错误处理，如果K大于数组个数，不可能存在
class Solution {
    int Partition(vector<int> &A, int i, int j){
        int key = A[i];
        while(i < j){
            while(i < j && A[j] >= key)
                --j;
            swap(A[i], A[j]);
            while(i < j && A[i] <= key)
                ++i;
            swap(A[i], A[j]);
        }
        return i;
    }
    int getKthNum(vector<int> A, int k){
        int start = 0;
        int end = A.size() - 1;
        int idx = Partition(A, start, end);
        while(idx != k - 1){
            if(idx > k - 1){
                end = idx - 1;
                idx = Partition(A, start, end);
            } else{
                start = idx + 1;
                idx = Partition(A, start, end);
            }
        }
        return A[idx];
    }
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || k < 1 || k > input.size())
            return res;
        int kNum = getKthNum(input, k);
        int i = 0;
        for(; i < input.size(); ++i){
            if(input[i] < kNum)
                res.push_back(input[i]);
        }
		// 因为存在重复的元素，不能小于等于的都算进去，可能多算了
		// 先把小于的算进去，剩下几个空位就都是等于的值
        for(i = res.size() ; i < k; ++i){
            res.push_back(kNum);
        }
        return res;
    }
}; 

// 对于海量数据情况，维护一个K大小的大顶堆
// greater<int>会使用特殊头文件，参考之前该题代码
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.size() < k || k < 1)
            return vector<int>();
        multiset<int, greater<int>> leastNumber;
        multiset<int, greater<int> >::iterator iter;
        for (auto i : input) {
            if (leastNumber.size() < k)
                leastNumber.insert(i);
            else {
                iter = leastNumber.begin();
                if (i < *iter) {
                    leastNumber.erase(*iter);
                    leastNumber.insert(i);
                }
            }
        }
        return vector<int>(leastNumber.begin(), leastNumber.end());
    }
};
 
