#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/strobogrammatic-number-ii/
/*中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
找到所有长度为 n 的中心对称数。*/
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n <= 0) return {""};
        if(n==1) return {"0","1","8"};
        vector<vector<string>> dp(n+1);
        dp[1] = {"0","1","8"};
        dp[2] = {"11","69","88","96"};
        vector<string> add1 = {"0","1","8"};
        vector<string> add2 = {"00","11","69","88","96"};
        string num;
        for(int i = 3, j,k,h; i <= n; ++i) {
            if(i&1) {// 奇数,我们在i-1偶数的基础上每个数中间位置add1
                for(j = 0; j < dp[i-1].size(); j++) {
                    num = dp[i-1][j];// i - 1是偶数 相当于在1691最中间插一位数(三种可能)
                    h = num.size() >> 1;
                    for(k = 0; k < add1.size(); k++) {
                        dp[i].push_back(num.substr(0,h)+add1[k]+num.substr(h));
                    }
                }
            }
            else {// i是偶数，我们在i-2偶数基础上每个数中间位置add2
                for(j = 0; j < dp[i-2].size(); j++) {
                    num = dp[i-2][j];// i - 2是偶数 相当于在169691最中间插两位数(五种可能)
                    h = num.size() >> 1;
                    for(k = 0; k < add2.size(); k++) {
                        dp[i].push_back(num.substr(0,h)+add2[k]+num.substr(h));
                    }
                }
            }
        }
        return dp[n];
    }
};