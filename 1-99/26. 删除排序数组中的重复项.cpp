#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newIndex = 0;
        for(int i = 0; i < nums.size(); i++) {
            nums[newIndex++] = nums[i];
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return newIndex;
    }
};