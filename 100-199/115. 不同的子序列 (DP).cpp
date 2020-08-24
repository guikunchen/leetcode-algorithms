#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t){// 计算s子序列中t出现的次数
        vector<vector<long>> dp(t.size()+1, vector<long>(s.size()+1, 0));
        // 初始化第一行
        for(int j=0; j<=s.size(); ++j) dp[0][j] = 1;
        // dp[i][j]表示s前j个字符里包括多少个，t(前i个)
        
        for(int i=1; i<=t.size(); i++)
            for(int j=1; j<=s.size(); j++){
                // 是否相等都要加上前面的值
                dp[i][j] = dp[i][j-1];
                // 相等时加上，上一个字符匹配得出的结果
                if(s[j-1] == t[i-1]) dp[i][j] += dp[i-1][j-1];
            }
        return dp[t.size()][s.size()];
    }
};

class Solution {
public:
    // 降低空间复杂度的动态规划
    int numDistinct(string s, string t){
        // 初始化第一行
        vector<long> dp(s.size()+1, 1);
        // 记录上一个保存的值
        int pre = 1;
        for(int i=1; i<=t.size(); ++i)
            for(int j=0; j<=s.size(); ++j){
                int tem = dp[j];
                if(j==0) dp[j] = 0;
                else {
                    // 是否相等都要加上前面的值
                    dp[j] = dp[j-1];
                    // 相等时加上，上一个字符匹配得出的结果
                    if(s[j-1] == t[i-1]) dp[j] += pre;
                }
                pre = tem;
            }
 
        return dp[s.size()];
    }
};