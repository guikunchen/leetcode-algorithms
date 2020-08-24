#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/find-peak-element/
/*峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。

示例 1:

输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5 
解释: 你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。 */
class Solution {// 首先要注意题目条件，在题目描述中出现了 nums[-1] = nums[n] = -∞，这就代表着
public://  只要数组中存在一个元素比相邻元素大，那么沿着它一定可以找到一个峰值

    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])// 恰好位于降序序列或者一个局部下降坡度中
                r = mid;
            else// 恰好位于升序序列或者一个局部上升坡度
                l = mid + 1;
        }
        return l;
    }
};