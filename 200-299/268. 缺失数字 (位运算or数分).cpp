#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/missing-number/

class Solution {// 除了缺少的那个数字，其他的都异或两次等于0
public:
    int missingNumber(vector<int>& nums) {
    	int miss = nums.size();
    	for(int i = 0; i < miss; i++) {
    		miss ^= i ^ nums[i];
    	}
    	return miss;
    }

    int missingNumber(vector<int>& nums) {
    	int expectedSum = nums.size() * (nums.size() + 1)/2;
    	int actualSum = 0;
        for (int num : nums) actualSum += num;
        return expectedSum - actualSum;
    }
};