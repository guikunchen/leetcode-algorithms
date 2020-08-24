#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/container-with-most-water/

class Solution {
public:
	// 最难的地方在于证明双指针的正确性
	// 如果移动高柱子指针，面积是一定会减小的，因为长度距离在变小，且高度只能小于或等于矮的柱子。因此只能移动矮的柱子这边才有可能使得高度比矮柱子大。
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return 0;

        int ans = 0;
        int begin = 0, end = height.size() - 1;
        while(begin < end) {
        	int cur = min(height[begin], height[end]) * (end - begin);
        	ans = max(ans, cur);
        	if(height[begin] <= height[end]) {
        		begin++;
        	} else {
        		end--;
        	}
        }
        return ans;
    }
};