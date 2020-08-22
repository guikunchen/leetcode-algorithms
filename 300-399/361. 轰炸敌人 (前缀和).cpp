#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/bomb-enemy
/*请你计算一个炸弹最多能炸多少敌人。

由于炸弹的威力不足以穿透墙体，炸弹只能炸到同一行和同一列没被墙体挡住的敌人。

注意：你只能把炸弹放在一个空的格子里

示例:

输入: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
输出: 3 
解释: 对于如下网格

0 E 0 0 
E 0 W E 
0 E 0 0

假如在位置 (1,1) 放置炸弹的话，可以炸到 3 个敌人*/

// 分别计算4个方向的前缀和，每个位置的数量是四个前缀和相加
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size(), i, j, pre = 0;
        vector<vector<int>> ans(m, vector<int>(n,0));
        //分四个方向求前缀和
        for(i = 0; i < m; ++i)// 从上到下
            for(j = 0, pre=0; j < n; ++j)// 从左往右
            {
                if(grid[i][j] =='W')
                    pre = 0;
                else if(grid[i][j] =='E')
                    pre++;
                else
                    ans[i][j] += pre;
            }
        for(i = 0; i < m; ++i)// 从上到下
            for(j = n-1, pre=0; j >= 0; --j)// 从右往左
            {
                if(grid[i][j] =='W')
                    pre = 0;
                else if(grid[i][j] =='E')
                    pre++;
                else
                    ans[i][j] += pre;
            }
        for(j = 0; j < n; ++j)// 从左往右
            for(i = 0, pre=0; i < m; ++i)// 从上到下
            {
                if(grid[i][j] =='W')
                    pre = 0;
                else if(grid[i][j] =='E')
                    pre++;
                else
                    ans[i][j] += pre;
            }
        for(j = 0; j < n; ++j)// 从左往右
            for(i = m-1, pre=0; i >= 0; --i)// 从下到上
            {
                if(grid[i][j] =='W')
                    pre = 0;
                else if(grid[i][j] =='E')
                    pre++;
                else
                    ans[i][j] += pre;
            }

        int maxcount = 0;
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
                maxcount = max(maxcount, ans[i][j]);
        return maxcount;
    }
};