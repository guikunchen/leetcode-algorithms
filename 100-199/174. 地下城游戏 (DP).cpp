#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/dungeon-game/

class Solution {
public:
	// 我们希望「从出发点到当前点的路径和」尽可能大，而「从出发点到当前点所需的最小初始值」尽可能小。这两条路径各有优劣。
	// 从左上到右下进行动态规划，无法直接确定到达下一个方案，因为有两个重要程度相同的参数同时影响后续的决策。
	// 也就是说，这样的动态规划是不满足「无后效性」的。

	// 从右下往左上，只需要考虑「从出发点到终点所需的最小初始值」
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        // 令 dp[i][j]表示从坐标到终点所需的最小初始值。
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));// 把无效值变为最大值
        dp[n][m - 1] = dp[n - 1][m] = 1;// dp[n−1][m] 和 dp[n][m-1] 均为无效值，因此我们给这两个值赋值为 1。
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int minn = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(minn - dungeon[i][j], 1);// 最小初始值至少为1，0就死掉了
            }
        }
        return dp[0][0];
    }
};