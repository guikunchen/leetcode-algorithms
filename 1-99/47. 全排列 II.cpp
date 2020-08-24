#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/permutations-ii/
// 这题给定的数字里有重复字符，要求输出的全排列不能有重复
// 跟31题结合起来 https://leetcode-cn.com/problems/next-permutation/
class Solution {
public:
    bool nextPermutation(vector<int>& nums) {
        auto i = is_sorted_until(nums.rbegin(), nums.rend()); // 找到末尾的一个降序段[s]及其前一个元素i
        bool has_next = i != nums.rend();
        if(has_next) {
            iter_swap(i, upper_bound(nums.rbegin(), i, *i));  // 找到[s]中比i大的数中最小的
            reverse(nums.rbegin(), i);                        // 序列反转
        }
        return has_next;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        result.push_back(nums);
        while(nextPermutation(nums)) {
            result.push_back(nums);
        }
        return result;
    }
};