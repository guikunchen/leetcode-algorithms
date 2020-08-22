#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/smallest-rectangle-enclosing-black-pixels
/*假设，这里我们用的是一张黑白的图片，那么 0 代表白色像素，1 代表黑色像素。
其中黑色的像素他们相互连接，也就是说，图片中只会有一片连在一块儿的黑色像素（像素点是水平或竖直方向连接的）。
那么，给出某一个黑色像素点 (x, y) 的位置，你是否可以找出包含全部黑色像素的最小矩形（与坐标轴对齐）的面积呢？
输入:
[
  "0010",
  "0110",
  "0100"
]
和 x = 0, y = 2

输出: 6
*/
class Solution {// 简单的模板题，BFS、DFS都可以做，找两个方向坐标的极限值
    int x1 = INT_MAX, x2 = -1;
    int y1 = INT_MAX, y2 = -1;
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size(), i, j, nx, ny, k;
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        queue<vector<int>> q;// BFS
        q.push({x,y});
        image[x][y] = '0';//访问过了
        while(!q.empty())
        {
            i = q.front()[0];
            j = q.front()[1];
            q.pop();
            x1 = min(x1, i);
            x2 = max(x2, i);
            y1 = min(y1, j);
            y2 = max(y2, j);
            for(k = 0; k < 4; ++k)
            {
                nx = i + dir[k][0];
                ny = j + dir[k][1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny]=='1')
                {
                    q.push({nx, ny});
                    image[nx][ny] = '0';//访问过了
                }
            }
        }
        return (x2-x1+1)*(y2-y1+1);// 边长乘边长
    }
};