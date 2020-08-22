// https://leetcode-cn.com/problems/132-pattern/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;

        vector<int> preMin(n, INT_MAX);
        preMin[0] = nums[0];
        for(int i = 1; i < n; i++) {
            preMin[i] = min(nums[i], preMin[i - 1]);
        }

        stack<int> st;// 存的是132的2
        for(int j = n - 1; j >= 1; j--) {
            if(nums[j] > preMin[j]) {
                while(!st.empty() && st.top() <= preMin[j]) {
                    st.pop();
                }
                if(!st.empty() && st.top() < nums[j]) {
                    return true;
                }
                st.push(nums[j]);
            }
        }
        return false;
    }
};