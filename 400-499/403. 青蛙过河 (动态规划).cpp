// https://leetcode-cn.com/problems/frog-jump/

class Solution {// dp[i]表示能跳到i位置的上一步所跳的步数的集合！
public:
    bool canCross(vector<int>& stones) {
    	unordered_map<int, unordered_set<int>> dp;
    	for(auto stone : stones) {
    		dp[stone] = unordered_set<int>();
    	}
    	dp[stones[0]].insert(0);
    	for(int i = 0; i < stones.size(); i++) {
    		for(int k : dp[stones[i]]) {
    			for(int step = k - 1; step <= k + 1; step++) {
    				if(step > 0 && dp.count(stones[i] + step)) {// 只能往前跳
    					dp[stones[i] + step].insert(step);
    				}
    			}
    		}
    	}
    	return dp[stones[stones.size() - 1]].size() > 0;
    }
};