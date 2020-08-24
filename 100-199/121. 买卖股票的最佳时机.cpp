#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    // minprice是当前的局部最小值
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
    
	// 限制最大交易次数1.
	int maxProfit_k_1(int[] prices) {
	    int n = prices.length;
	    // base case: dp[-1][0] = 0, dp[-1][1] = -infinity
	    int dp_i_0 = 0, dp_i_1 = Integer.MIN_VALUE;
	    for (int i = 0; i < n; i++) {
	        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
	        dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
	        // dp[i][1] = max(dp[i-1][1], -prices[i])
	        dp_i_1 = Math.max(dp_i_1, -prices[i]);
	    }
	    return dp_i_0;
	}
    
    // 节省空间之前
    for (int i = 0; i < n; i++) {
        if (i - 1 == -1) {
            dp[i][0] = 0;
            // 解释：
            //   dp[i][0] 
            // = max(dp[-1][0], dp[-1][1] + prices[i])
            // = max(0, -infinity + prices[i]) = 0
            dp[i][1] = -prices[i];
            //解释：
            //   dp[i][1] 
            // = max(dp[-1][1], dp[-1][0] - prices[i])
            // = max(-infinity, 0 - prices[i]) 
            // = -prices[i]
            continue;
        }
        dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = Math.max(dp[i-1][1], -prices[i]);
    }
    return dp[n - 1][0];
};