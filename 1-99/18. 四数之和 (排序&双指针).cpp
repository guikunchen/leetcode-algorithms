#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;

        for(int first = 0; first < nums.size(); first++) {
            if(first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            for(int second = first + 1; second < nums.size(); second++) {
            	// 先固定first 和 second 两个索引
                if(second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                int fourth = nums.size() - 1;
                int newTarget = target - (nums[first] + nums[second]);
                // third 和 fourth 作为双指针，从左右两边往中间靠拢
                for(int third = second + 1; third < nums.size(); third++) {
                    if(third > second + 1 && nums[third] == nums[third - 1]) {
                        continue;
                    }
                    while(third < fourth && nums[third] + nums[fourth] > newTarget) {
                        fourth--;
                    }
                    if(third == fourth) break;
                    if(nums[third] + nums[fourth] == newTarget) {
                        ans.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                    }
                }
            }
        }
        return ans;
    }
};