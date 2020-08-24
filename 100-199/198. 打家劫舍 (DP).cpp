#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/house-robber/ 第二题213

class Solution {
public:
    // 普通数组
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = (int)nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp [i - 1]);
        }
        return dp[n - 1];
    }
    // 滚动数组，优化空间
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = (int)nums.size();
        if(n == 1) return nums[0];
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            int temp = second;
            second = max(nums[i] + first, second);
            first = temp;
        }
        return second;
    }
};