#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph/

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

    void countUnion() {
        int count = 0;
        for(int i = 0; i < parent.size(); ++i) {
            if(i == find(i)) {
                count++;
            }
        }
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;// 基于rank的优化
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto& e : edges)
            uf.unite(e[0],e[1]);
        return uf.countUnion();
    }
};