#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/super-ugly-number/ 第264题

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n);
        vector<int> positions(primes.size(), 0);

        // 初始化
        dp[0]=1;

        for (int i = 1; i < n ;++i) {
            // 选出最小的数字作为下一个丑数
            int num = INT_MAX;
            for(int k = 0; k < primes.size(); k++) {
                num = min(num, dp[positions[k]] * primes[k]);
            }
            dp[i] = num;
            cout << num << endl;

            // 更新索引，将该数字对应的因子指针向前移动一步。
            for(int k = 0; k < primes.size(); k++) {
                if(dp[i] == dp[positions[k]] * primes[k]) {
                    positions[k]++;
                }
            }
        }
        return dp[n - 1];
    }
};