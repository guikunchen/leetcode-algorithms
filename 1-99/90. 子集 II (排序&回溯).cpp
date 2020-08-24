#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/subsets-ii/

class Solution {
public:
	vector<vector<int>> res;

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	    sort(nums.begin(), nums.end())
	    vector<int> track;// 记录走过的路径
	    backtrack(nums, 0, track);
	    return res;
	}

	void backtrack(vector<int>& nums, int start, vector<int>& track) {
	    res.push_back(track);
	    for (int i = start; i < nums.size(); i++) {
	    	if(i > start && nums[i] == nums[i - 1]) {// 这边要大于start而不是0，122有个子集是122，如果大于0就跳过去了
	    		continue;
	    	}
	        // 做选择
	        track.push_back(nums[i]);
	        // 回溯
	        backtrack(nums, i + 1, track);
	        // 撤销选择
	        track.pop_back();
	    }
	}
};