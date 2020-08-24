#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/unique-paths/

class Solution {
public:
    // 用动态规划的思想，空间复杂度 nm
    // 通过左上算出右下，边界为1
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int i = 0; i < n; i++) dp[0][i] = 1;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    // 通过优化可以空间复杂度n
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }

    // 也可以用排列组合，(m + n - 2) 选（m - 1），选某几步向下走，那么其他的只能向右走。
};