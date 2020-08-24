#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/regular-expression-matching/
//和第44题对比
/*

动态规划，dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配

如果 p.charAt(j) == s.charAt(i) : dp[i][j] = dp[i-1][j-1]；
如果 p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1]；
如果 p.charAt(j) == '*'：
    如果 p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2] //in this case, a* only counts as empty
    如果 p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == '.'：
        dp[i][j] = dp[i-1][j] //in this case, a* counts as multiple a
        or dp[i][j] = dp[i][j-1] // in this case, a* counts as single a，其实是多余的，因为上一行每次都会吃掉一个字符，直到empty，所以不用单独考虑作为一个。
        or dp[i][j] = dp[i][j-2] // in this case, a* counts as empty

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];// 因为j代表前j个，转化为数组中的实际索引需要-1。
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];// 代码里也省略了a*作为a的情况 f[i][j-1]
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};
