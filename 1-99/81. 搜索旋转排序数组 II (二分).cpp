#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int middle = low + ((high - low) >> 1);

            if(nums[middle] == target) {
                return true;
            }

            if (nums[low] == nums[middle]) {// 10111 11100    0可能在左边也可能在右边
                low++;// 因为有重复元素，相等的时候分不清前面有序还是后面有序，只能左边指针右移一位再二分
            } else if(nums[low] <= nums[middle]) {
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
        return false;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
        {
            return n;
        }
        int sp = 1;
        // 若相等，往右移动快指针
        // 若不等，慢指针右移，然后把快指针所指向的元素写入慢指针所在位置
        for(int fp = 2; fp < n; fp++)
        {
            if(nums[fp] != nums[sp - 1])
            {
                nums[++sp] = nums[fp];
            }
        }
        return sp + 1;
    }
};