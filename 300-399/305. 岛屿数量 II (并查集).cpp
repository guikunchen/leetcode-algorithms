#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/number-of-islands-ii/ 第一题200
class UnionFind {
public:
    UnionFind(int n) {
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int i) {
        // if (parent[i] != i) {
        //     parent[i] = find(parent[i]);// 路径压缩，遍历的时候使每个节点都指向根节点
        //     // 也可以用路径分裂，路径减半
        // }
        while(i != parent[i]){// 路径减半
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;// 把rooty根节点的树嫁接到rootx上
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;// 仅当两树高度相等时，高度才要加1
        }
    }

private:
    vector<int> parent;
    vector<int> rank;// 基于rank的优化
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int N = m*n, pos, x, y;
        vector<vector<int>> grid(m,vector<int>(n,0));
        UnionFind uf(N);
        vector<int> ans(positions.size());
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        
        for(int i = 0, k; i < positions.size(); ++i) {
            if (grid[positions[i][0]][positions[i][1]] == 1) {// 重复添加岛屿，忽视
                continue;
            }

            ans[i] = (i>0 ? ans[i-1] : 0 )+1;//先把这个岛屿算作孤立+1
            grid[positions[i][0]][positions[i][1]] = 1;//标记为岛屿
            pos = positions[i][0]*n+positions[i][1];//对应并查集中的位置
            for(k = 0; k < 4; ++k) {// 四个方向
                x = positions[i][0] + dir[k][0];
                y = positions[i][1] + dir[k][1];//周围坐标x,y
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1) {
                    if(uf.find(pos) != uf.find(x*n+y)) {// 不是同一个集合
                        uf.unite(pos, x*n+y);// 合并
                        ans[i]--;//岛屿数量减1
                    }
                }
            }
        }
        return ans;
    }
};