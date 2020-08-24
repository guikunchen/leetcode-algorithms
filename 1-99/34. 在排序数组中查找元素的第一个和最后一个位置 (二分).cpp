#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
	// 找到边界，可能是很长的一串相同数字，所以二分搜索更换边界时需要做稍微的改动，算是小小的变形
	int searchUpperBound(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1;
		while(low <= high) {
			int middle = low + (high - low) / 2;
			int upper = middle + 1;
			if(nums[middle] == target && (upper == nums.size() || nums[upper] > target)) {
				return middle;
			}
			if(nums[middle] > target) {
				high = middle - 1;
			} else {
				low = upper;
			}
		}
		return -1;
	}
	int searchLowerBound(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1;
		while(low <= high) {
			int middle = low + (high - low) / 2;
			int lower = middle - 1;
			if(nums[middle] == target && (lower == -1 || nums[lower] < target)) {
				return middle;
			}
			if(nums[middle] >= target) {
				high = lower;
			} else {
				low = middle + 1;
			}
		}
		return -1;
	}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(searchLowerBound(nums, target));
        ans.push_back(searchUpperBound(nums, target));
        return ans;
    }


    // 类似的题目，如何找到第一个大于6的数？
    // 二分搜索，要满足两个条件： 大于6   且 为左边界或左边的数小于等于6   
};