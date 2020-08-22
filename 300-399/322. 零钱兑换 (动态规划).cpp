#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;// 因为amount最多由amount个1块硬币组成
        vector<int> dp(amount + 1, Max);// dp[i]表示组成i块钱的最小硬币个数
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {// 从小到大，有点像丑数的思想
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};