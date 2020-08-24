#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int newIndex = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[newIndex++] = nums[i];
            } else {
                while(i + 1 < nums.size() && val == nums[i + 1]) {
                    i++;
                }
            }
        }
        return newIndex;
    }
};