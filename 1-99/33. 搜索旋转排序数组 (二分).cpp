#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
        	int middle = low + ((high - low) >> 1);

        	if(nums[middle] == target) {
        		return middle;
        	}

        	if(nums[low] <= nums[middle]) {
        		if(nums[middle] > target && nums[low] <= target) {
        			high = middle - 1;
        		} else {
        			low = middle + 1;
        		}
        	} else {
        		if(nums[middle] < target && nums[high] >= target) {
        			low = middle + 1;
        		} else {
        			high = middle - 1;
        		}
        	}
        }
        return -1;
    }

    // 如果数组不定长，那么先二倍增加，估算一个high，然后用二分搜索确定数组的长度
    // 结束条件为，该位置null  且   前一个位置不为null
};