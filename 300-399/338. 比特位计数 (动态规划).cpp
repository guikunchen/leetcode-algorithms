#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        for(int i = 1; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);// 最低位的差距
        }
        return dp;
    }
};