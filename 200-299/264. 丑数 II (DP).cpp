#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/ugly-number-ii/
// 求第n个丑数

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);

        // 初始化
        dp.at(0)=1;
        int p_2,p_3,p_5;
        p_2=p_3=p_5=0;

        for (int i=1;i<n;++i) {
            // 选出最小的数字作为下一个丑数
            dp.at(i)=min(min(2*dp.at(p_2),3*dp.at(p_3)),5*dp.at(p_5));

            // 更新索引，将该数字对应的因子指针向前移动一步。
            // 不能用else if是因为，一个丑数乘2和另一个丑数乘3、5是有可能相等的，所以索引要同时移动
            if (dp.at(i)==2*dp.at(p_2))
                ++p_2;
            if (dp.at(i)==3*dp.at(p_3))
                ++p_3;
            if (dp.at(i)==5*dp.at(p_5))
                ++p_5;
        }
        return dp[n - 1];
    }
};