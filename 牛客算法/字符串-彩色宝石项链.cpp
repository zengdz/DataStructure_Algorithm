// 给定的字符串表示一串项链，可以首尾连接，每种字母分别代表项链的一种宝石
// 要求截取连续的一段，其中包含A,B,C,D,E这五种宝石 
// 如果截取成功，剩下的归自己，否则什么都得不到，怎么截取可以得到最多宝石 
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 判断字符串是否包含这五种，使用位标记
// 遇到了则对应位或运算置1，重复运算结果相同，最后看5位是否全为1
// 注意首尾相连，可以构造辅助字符串，即在原串后续上原串
// 但是遍历时只需处理到原串的后5位置，因为后面是重复的了 
int main()
{
    string str;
    while(cin >> str){
        string helpStr = str + str;
        int min_len = str.size(); // 初值为原串的长度 
        for(int i = 0; i < str.size() + 5; ++i) {
        	// 这两个变量一定在两层循环之间，每一轮要更新为初值 
            int flag = 0x00;
            int temp_len = 0;
            for(int j = i; j < str.size() + 5; ++j){
                ++temp_len;
                if(helpStr[j] >= 'A' && helpStr[j] <= 'E')
                	flag |= 1 << (helpStr[j] - 'A');
                // 若满足条件，计算此时最小长度 
				if(flag == 0x1f) {
					min_len = min(min_len, temp_len); 
                    break;
                } 
            }   	
        }
        // 原串长度减去最小截取的长度就是自己得到的最大长度 
        cout << str.size() - min_len << endl;
    }
    
    return 0;
}

