#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/shortest-distance-from-all-buildings
/*你是个房地产开发商，想要选择一片空地 建一栋大楼。
你想把这栋大楼够造在一个距离周边设施都比较方便的地方，通过调研，你希望从它出发能在 最短的距离和 内抵达周边全部的建筑物。
请你计算出这个最佳的选址到周边全部建筑物的 最短距离和。

提示：
你只能通过向上、下、左、右四个方向上移动。

给你一个由 0、1 和 2 组成的二维网格，其中：

0 代表你可以自由通过和选择建造的空地
1 代表你无法通行的建筑物
2 代表你无法通行的障碍物*/
class Solution {// 从每个房屋出发，dis 数组记录每个房屋到空地的距离
public:// totaldis 数组记录，每个房子遍历空地后，之前所有房子到空地的总距离
    int shortestDistance(vector<vector<int>>& grid) {
        //从每个建筑物出发去找空地，空地对每个建筑物的距离累积
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        vector<vector<int>> build;
        int i, j, k, x, y, mindis;
        int m = grid.size(), n = grid[0].size();
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(grid[i][j]==1)
                    build.push_back({i,j});
        vector<vector<int>> dis(m, vector<int>(n, 0));
        //记录单次遍历1个房屋到空地的距离
        vector<vector<int>> totaldis(m, vector<int>(n, 0));
        //记录所有房屋到空地的距离
        int emptyPlace = 0;//空地的标记数字
        for(auto& pos : build)//遍历房子
        {
            queue<vector<int>> q;
            // vector<vector<bool>> visited(m, vector<bool>(n,false));
            q.push({pos[0], pos[1]});//x,y
            mindis = INT_MAX;
            while(!q.empty())
            {
                x = q.front()[0];
                y = q.front()[1];
                q.pop();
                for(k = 0; k < 4; ++k)
                {
                    i = x + dir[k][0];
                    j = y + dir[k][1];
                    if(i>=0 && i<m && j>=0 && j<n && 
                            grid[i][j] == emptyPlace)//空地
                    {
                        dis[i][j] = dis[x][y]+1;//该房子到ij空地的距离
                        totaldis[i][j] += dis[i][j];//之前所有房子到这的距离和
                        mindis = min(mindis, totaldis[i][j]);
                        // visited[i][j] = true;
                        grid[i][j]--;//从lx_lx大佬那学的，不用开访问数组了
                        q.push({i,j});
                    }
                }
            }
            if(mindis == INT_MAX)
                return -1;//该房屋不能到达任何空地
            emptyPlace--;//更新空地的标记，免开访问标记数组
        }
        return mindis==INT_MAX ? -1 : mindis;
    }
};