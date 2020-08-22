#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp_i_0 = 0, dp_i_1 = INT_MIN;// 还没开始的时候利润为0，不可能持有股票
        for(int i = 0; i < prices.size(); i++) {
            int temp = dp_i_0;
            // 坚持不买，或者卖出，都会转到0这个状态
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            // 继续持有，或者买入，都会转到1这个状态，买入的时候需要手续费
            dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
        }
        return dp_i_0;
    }
};