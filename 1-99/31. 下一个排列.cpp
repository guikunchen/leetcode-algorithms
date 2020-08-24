#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/next-permutation/

class Solution {
public:
	// 从右往左，找第一个减小的数，记为a，然后从a往右边找到一个最小的又比a大的数，与a交换。
	// 然后把a的右边一个元素到末尾逆序一下（本来是降序，改为升序）
    void nextPermutation(vector<int>& nums) {
        int search = nums.size() - 1;
        while(search > 0 && nums[search] <= nums[search - 1]) {
        	search--;
        }
        if(search == 0) {
        	reverse(nums.begin(), nums.end());
        } else {
        	search--;
        	int count = 1;
        	while(search + count < nums.size() && nums[search + count] > nums[search]) {
        		++count;
        	}
        	swap(nums[search], nums[search + count - 1]);
        	reverse(nums.begin() + search + 1, nums.end());
        }
    }
};