#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/3sum-closest/

class Solution {
public:
	void update(int &ans, int replace, int target) {
		if(abs(ans - target) > abs(replace - target)) {
			ans = replace;
		}
	}
    int threeSumClosest(vector<int>& nums, int target) {
    	int size = nums.size();
    	sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];

        for(int first = 0; first < size; first++) {// 固定first
            if(first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int i = first + 1, j = size - 1;
            while(i < j) {
            	int sum = nums[first] + nums[i] + nums[j];
            	if(sum == target) return target;
            	update(ans, sum, target);
            	if(sum > target) {// 右往左
            		j--;
            		while(i < j && nums[j] == nums[j + 1]) {
            			j--;
            		}
            	} else {// 左往右
            		i++;
            		while(i < size && nums[i] == nums [i - 1]) {
            			i++;
            		}
            	}
            }
        }
        return ans;
    }
};