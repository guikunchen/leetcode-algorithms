#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k > (n >> 1)) {// 相当于不限制交易次数
            int dp_i_0 = 0, dp_i_1 = INT_MIN;// 还没开始的时候利润为0，不可能持有股票
            for(int i = 0; i < prices.size(); i++) {
                int temp = dp_i_0;
                // 坚持不买，或者卖出，都会转到0这个状态
                dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
                // 继续持有，或者买入，都会转到1这个状态，买入的时候需要手续费
                dp_i_1 = max(dp_i_1, temp - prices[i]);
            }
            return dp_i_0;
        } else {
            vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k+1, vector<int>(2)));
            for(int i = 0; i <= k; i++) {// base case
                dp[0][i][0] = 0;
                dp[0][i][1] = INT_MIN;
            }
            for(int i = 1; i <= n; i++) {
                for(int j = k; j >= 1; j--) {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
                }
            }
            return dp[n][k][0];
        }
    }
};