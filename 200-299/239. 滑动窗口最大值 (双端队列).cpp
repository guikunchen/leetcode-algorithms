#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

// https://leetcode-cn.com/problems/sliding-window-maximum/

class Solution {
public:
	int manageQueue(deque<int>& deq, vector<int>& nums, int index, int k){
		if(!deq.empty() && deq.front() == index - k){// 去掉不应在滑动窗口的索引，最多有一个
			deq.pop_front();
		}

		while(!deq.empty() && nums[deq.back()] <= nums[index]){
			deq.pop_back();
		}

		deq.push_back(index);
		return nums[deq.front()];
	}

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	deque<int> deq;// 存储的是索引
    	vector<int> ans;
    	if(nums.size() * k == 0) return ans;
    	if(k == 1) return nums;

    	for(int i = 0; i < k - 1; i++){
    		manageQueue(deq, nums, i, k);
    	}

    	for(int i = k - 1; i < nums.size(); i++){
    		ans.push_back(manageQueue(deq, nums, i, k));
    	}

    	return ans;
    }
};