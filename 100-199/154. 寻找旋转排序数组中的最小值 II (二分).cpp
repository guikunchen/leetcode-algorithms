#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
// 有重复元素
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {/* 明确中值 < 右值，最小值在左半边，收缩右边界 */ 
                high = pivot;
            } else if (nums[pivot] > nums[high]) {/* 中值 > 右值，最小值在右半边，收缩左边界 */ 
                low = pivot + 1;
            } else {// 不能确定，所以只能窗口缩小一格
                high -= 1;
            }
        }
        return nums[low];
    }
};