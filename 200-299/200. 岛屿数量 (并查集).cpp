#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/number-of-islands/ 第二题305

// 如果用图的方式来做，碰到1，那岛屿的数量加1。
// 然后以该点为起点进行遍历(DFS或BFS)，所有遍历到的点都置0。
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
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
            --count;// union后岛屿数量-1
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;// 基于rank的优化
    int count;// 岛屿数量
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	int nr = grid.size();
        if(nr == 0) return 0;
        int nc = grid[0].size();
        UnionFind uf(grid);

        for(int r = 0; r < nr; r++){
        	for(int c = 0; c < nc; c++){
        		if(grid[r][c] == '1'){
        			// grid[r][c] = '0';// 不是必须的，小优化，少了几次union而已
        			// 检查上下左右四个方向有没有可以合并的
        			if (r - 1 >= 0 && grid[r-1][c] == '1') uf.unite(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1') uf.unite(r * nc + c, (r+1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
        		}
        	}
        }

        return uf.getCount();
    }
};