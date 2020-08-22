// https://leetcode-cn.com/problems/shuffle-an-array


class Solution {
    vector<int> nums;
    vector<int> copy;
public:
    Solution(vector<int>& nums) {
        this->nums.assign(nums.begin(), nums.end());
        this->copy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        nums.clear();
        nums.assign(copy.begin(), copy.end());
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {// 要保证有n!种可能
        for(int i = 0; i < nums.size(); i++) {
            int rd = rand() % (n - i) + i;// 从[i, n-1]里挑一个
            swap(nums[rd], nums[i]);// 交换不会相互影响
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */