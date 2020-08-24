#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/wildcard-matching/
//和第10题对比
/*

动态规划，dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配

如果 p.charAt(j) == s.charAt(i) : dp[i][j] = dp[i-1][j-1]；
如果 p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1]；
如果 p.charAt(j) == '*'：
        dp[i][j] = dp[i-1][j] //in this case, * counts as multiple char
        or dp[i][j] = dp[i][j-1] // in this case, * counts as empty

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};