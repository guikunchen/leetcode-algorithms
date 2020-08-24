#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    // 有两次交易次数持有的最大利润，就是前一天一次交易次数没持有时减去买入的钱
    int maxProfit(vector<int>& prices) {
        int dp_i10 = 0, dp_i11 = INT_MIN;// 还没开始的时候利润为0，不可能持有股票
        int dp_i20 = 0, dp_i21 = INT_MIN;// 还没开始的时候利润为0，不可能持有股票
        for(int i = 0; i < prices.size(); i++) {
            dp_i20 = max(dp_i20, dp_i21 + prices[i]);
            dp_i21 = max(dp_i21, dp_i10 - prices[i]);// 顺序不能换
            dp_i10 = max(dp_i10, dp_i11 + prices[i]);
            dp_i11 = max(dp_i11, -prices[i]);// dp_i00 = 0，没有交易次数自然没有利润
        }
        return dp_i20;
    }
};