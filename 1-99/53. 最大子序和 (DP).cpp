#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

// https://leetcode-cn.com/problems/maximum-subarray/

class Solution {
public:
    // 动态规划
    // f(i) 以第i个元素结尾的最大子序和 f(i) = max(f(i)+nums[i], nums[i])
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int pre = 0, ans = nums[0];
        for(auto const &num : nums) {
            pre = max(num, pre + num);
            ans = max(ans, pre);
        }
        return ans;
    }
    // 分治
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        return maxSubArray(nums, 0, nums.size() - 1);
    }
    int maxSubArray(vector<int>& nums, int begin, int end) {
        if(begin == end) return nums[begin];

        int middle = begin + ((end - begin) >> 1);
        int leftMax = nums[middle], rightMax = nums[middle + 1];// 不可以设为0，考虑负数情况
        int leftSum = 0, rightSum = 0;
        for(int i = middle; i >= begin; i--) {
            leftSum += nums[i];
            leftMax = max(leftMax, leftSum);
        }
        for(int i = middle + 1; i <= end; i++) {
            rightSum += nums[i];
            rightMax = max(rightMax, rightSum);
        }
        int midMax = leftMax + rightMax;

        return max(midMax, max(maxSubArray(nums, begin, middle), maxSubArray(nums, middle + 1, end)));
    }
};