#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/house-robber-ii/ 第一题298 第三题337

// 从一排数组变成环形数组，第一家和最后一家不能同时抢
class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {

        int first = nums[start];
        int second = max(nums[start], nums[start + 1]);
        for(int i = start + 2; i < end; i++) {
            int temp = second;
            second = max(nums[i] + first, second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        return max(robRange(nums, 0, n-1), robRange(nums, 1, n));
    }
};