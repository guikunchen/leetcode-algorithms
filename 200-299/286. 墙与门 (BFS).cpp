#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/walls-and-gates
/*你被给定一个 m × n 的二维网格，网格中有以下三种可能的初始化值：
-1 表示墙或是障碍物      
0 表示一扇门             你可以认为通往门的距离总是小于 2147483647 的。
INF 无限表示一个空的房间。然后，我们用 2^31 - 1 = 2147483647 代表 INF。
你要给每个空房间位上填上该房间到 最近门的距离，如果无法到达门，则填 INF 即可。
给定二维网格：
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
运行完你的函数后，该网格应该变成：
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;
        const int INF = 2147483647;
        int m = rooms.size(), n = rooms[0].size();
        vector<pair<int, int>> directs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push(make_pair(i, j));// 所有门进行BFS
                }
            }
        }
        while (!q.empty()) {
            auto pos = q.front();q.pop();
            int x = pos.first, y = pos.second;
            int distance = rooms[x][y] + 1; 
            for (auto direct : directs) {
                int nx = x + direct.first, ny = y + direct.second;
                // 每个位置最多访问一次
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || rooms[nx][ny] != INF) continue;
                rooms[nx][ny] = distance; 
                q.push(make_pair(nx, ny));// 可到达的房间也可以进行BFS
            }
        }
        return;
    }
};