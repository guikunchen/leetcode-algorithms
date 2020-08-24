#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int n = nums.size();
    	vector<int> ans(n, 1);
    	for(int i = 1; i < n; i++) {
    		ans[i] = nums[i - 1] * ans[i - 1];
    	}
    	int base = nums[n - 1];
    	for(int i = n - 2; i >= 0; i--) {
    		ans[i] *= base;
    		base *= nums[i];
    	}
    	return ans;
    }
};