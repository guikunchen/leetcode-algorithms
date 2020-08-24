#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) return 0;// 不合法

        int begin = 1, end = nums.size() - 1;
        while(begin < end) {
            int mid = begin + ((end - begin) >> 1);
            int count = 0;
            for(num : nums) {
                if(num >= begin && num <= mid) {
                    count++;
                }
            }
            if(count > mid - begin + 1) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        return begin;
    }
};