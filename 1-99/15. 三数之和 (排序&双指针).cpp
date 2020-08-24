#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        // for(int first = 0; first < nums.size() - 2; first++) 不知道为啥不能-2，会报错
        // ans: vector.size() return a size_type which is an unsigned integral type
        for(int first = 0; first < nums.size(); first++) {
            if(first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int third = nums.size() - 1;
            int target = -nums[first];
            // 固定first，second 和third 作为双指针向中间靠拢
            for(int second = first + 1; second < nums.size(); second++) {
                if(second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                while(second < third && nums[third] + nums[second] > target) {
                    third--;
                }
                if(second == third) break;
                if(nums[third] + nums[second] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};