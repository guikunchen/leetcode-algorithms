#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/3sum-smaller
/*给定一个长度为 n 的整数数组和一个目标值 target，
寻找能够使条件 nums[i] + nums[j] + nums[k] < target 成立的三元组 i, j, k 个数
（0 <= i < j < k < n）。
*/
class Solution {
public:// 固定一点，双指针
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i, j, k, n = nums.size(), count = 0, sum;
        for(int i = 0; i < n-2; ++i) {// 固定第一点
            j = i+1, k = n-1;
            while(j < k) {
                sum = nums[i]+nums[j]+nums[k];
                if(sum < target){
                    count += k-j;// j=left, k=j+1..right的组合数
                    j++;
                } else {
                    k--;
                }
            }
        }
        return count;
    }
};