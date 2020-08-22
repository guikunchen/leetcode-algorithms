// https://leetcode-cn.com/problems/wiggle-subsequence/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
    	int n = nums.size();
    	vector<int> down(n, 1), up(n, 1);
    	// down[i]表示以num[i]降序结尾的最大长度
    	// up[i]表示以num[i]升序结尾的最大长度

    	for(int i = 1; i < nums.size(); i++) {
    		if(nums[i] > nums[i - 1]) {// 当前数大于上个数，这里是上升
    			up[i] = down[i - 1] + 1;
    			down[i] = down[i - 1];
    		} else if (nums[i] < nums[i - 1]) {// 当前数小于上个数，这里是下降
    			down[i] = up[i - 1] + 1;
    			up[i] = up[i - 1];
    		} else {// 相等的话就不更新了
    			up[i] = up[i - 1];
    			down[i] = down[i - 1];
    		}
    	}
    	return max(up[n - 1], down[n - 1]);
    }

    // 因为只依赖于前一个，所以可以优化到常数空间
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
    	int up = 1, down = 1;
    	for(int i = 1; i < nums.size(); i++) {
    		if(nums[i] > nums[i - 1]) {
    			up = down + 1;
    		} else if (nums[i] < nums[i - 1]) {
    			down = up + 1;
    		}
    	}
    	return max(up, down);
    }
};