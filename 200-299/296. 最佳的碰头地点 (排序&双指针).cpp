#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/best-meeting-point
/*有一队人（两人或以上）想要在一个地方碰面，他们希望能够最小化他们的总行走距离。
给你一个 2D 网格，其中各个格子内的值要么是 0，要么是 1。
这里，我们将使用 曼哈顿距离 来计算，其中 distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|。

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
输出: 6 
解析: 给定的三个人分别住在(0,0)，(0,4) 和 (2,2):
     (0,2) 是一个最佳的碰面点，其总行走距离为 2 + 2 + 2 = 6，最小，因此返回 6。

两个方向的坐标是独立的，独立考虑
然后在中位数的点是总距离最近的
按序搜集横纵坐标，双指针，两端点相减的距离累加
*/
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j, dis = 0;
        vector<int> x, y;
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
                if(grid[i][j])
                    x.push_back(i);
        for(j = 0; j < n; ++j)
            for( i = 0; i < m; ++i)
                if(grid[i][j])
                    y.push_back(j);
        // 这样放置 x y 已经是有序的了
        i = 0, j = x.size()-1;
        while(i < j)// 奇数个就在最中间那个碰面，偶数个就是不断累加坐标之差
            dis += x[j--]-x[i++];
        i = 0, j = y.size()-1;
        while(i < j)
            dis += y[j--]-y[i++];
        return dis;
    }
};