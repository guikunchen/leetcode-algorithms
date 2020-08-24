#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/graph-valid-tree
/*给定从 0 到 n-1 标号的 n 个结点，和一个无向边列表（每条边以结点对来表示），
请编写一个函数用来判断这些边是否能够形成一个合法有效的树结构。
输入: n = 5, 边列表 edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
输出: false
注意：你可以假定边列表 edges 中不会出现重复的边。
由于所有的边是无向边，边 [0,1] 和边 [1,0] 是相同的，
因此不会同时出现在边列表 edges 中。
*/
class UnionFind {
public:
    UnionFind(n) {
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

    int countUnion() {// 返回集合的数量
        int count = 0;
        for(int i = 0; i < parent.size(); i++) {
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
    bool validTree(int n, vector<vector<int>>& edges) {// 从0到n-1编号
        UnionFind uf(n);
        for(auto& edge : edges) {
            uf.unite(edge[0], edge[1]);
        }
        // 边数 + 1 等于节点数，且只有一个集合（最上边就是树的根节点）
        return edges.size()+1==n && u.countUni()==1;
    }
};