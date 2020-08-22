// https://leetcode-cn.com/problems/partition-equal-subset-sum/
// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
class Solution {
public:
	bool canPartition(vector<int>& nums) {
	    int sum = 0;
	    for (int num : nums) sum += num;
	    // 和为奇数时，不可能划分成两个和相等的集合
	    if (sum & 1 != 0) return false;

	    int n = nums.size();
	    sum = sum / 2;
	    // dp[i][j] = true 表示，对于容量为 j 的背包，若只是用前 i 个物品，可以有一种方法把背包恰好装满。
	    vector<vector<bool>> 
	        dp(n + 1, vector<bool>(sum + 1, false));
	    // 背包没有空间的时候，就相当于装满了，而当没有物品可选择的时候，肯定没办法装满背包。
	    for (int i = 0; i <= n; i++)
	        dp[i][0] = true;
	    
	    for (int i = 1; i <= n; i++) {
	        for (int j = 1; j <= sum; j++) {
	            if (j - nums[i - 1] < 0) {
	               // 背包容量不足，不能装入第 i 个物品
	                dp[i][j] = dp[i - 1][j]; 
	            } else {
	                // 不装入 或 装入背包
	                dp[i][j] = dp[i - 1][j] | dp[i - 1][j-nums[i-1]];
	            }
	        }
	    }
	    return dp[n][sum];
	}
};