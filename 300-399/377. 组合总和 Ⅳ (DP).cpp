// https://leetcode-cn.com/problems/combination-sum-iv/  39题 216题

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);// dp[i]是和为i的组合个数
        dp[0] = 1;// 一定要设为1，代表不添加数字，相当于加上个空集
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i < nums[j]) continue;
                // 不能直接写成dp[i] += dp[i - nums[j]]，相加越界
                dp[i] = (dp[i] >= INT_MAX - dp[i - nums[j]]) ? INT_MAX : dp[i] + dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};