#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/maximum-size-subarray-sum-equals-k
/*给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长子数组长度。
如果不存在任意一个符合要求的子数组，则返回 0。

注意:
nums 数组的总和是一定在 32 位有符号整数范围之内的。

示例 1:
输入: nums = [1, -1, 5, -2, 3], k = 3
输出: 4 
解释: 子数组 [1, -1, 5, -2] 和等于 3，且长度最长。

示例 2:
输入: nums = [-2, -1, 2, 1], k = 1
输出: 2 
解释: 子数组 [-1, 2] 和等于 1，且长度最长。

进阶:
你能使时间复杂度在 O(n) 内完成此题吗?*/

class Solution {// 子数组必须连续
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> m;// 前缀和，索引
        m[0] = -1;// 在nums[0] 出现了k，那么长度是0 - (-1) = 1
        int i, sum = 0, maxlen = 0;
        for(i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(m.count(sum-k))
                maxlen = max(maxlen, i-m[sum-k]);
            if(!m.count(sum))// 不存在的时候才要放进去，不可以替换，因为题目要求最长，所以i越小越好
                m[sum] = i;
        }
        return maxlen;
    }
};