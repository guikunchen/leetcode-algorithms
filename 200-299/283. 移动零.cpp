#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int noZeroCount = 0;
        for(auto num : nums) {// 所有不为零的数字都覆盖到最左边，刚好可以保证相对顺序
            if(num | 0) {
                nums[noZeroCount++] = num;
            }
        }
        for(int i = noZeroCount; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};