#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.at(0).size();
        vector<int> dp(m);
        dp[0] = grid[0][0];
        for(int i = 1; i < m; i++) {
            dp[i] = grid[0][i] + dp[i - 1];
        }
        for(int i = 1; i < n; i++) {
            dp[0] += grid[i][0];
            for(int j = 1; j < m; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp.back();
    }
};