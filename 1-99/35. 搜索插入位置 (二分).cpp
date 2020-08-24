#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index;
        for(index = 0; index < nums.size(); index++) {
            if(nums[index] >= target) {
                break;
            }
        }
        return index;
    }
};