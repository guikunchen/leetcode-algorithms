#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/surrounded-regions/


class Solution {
public:
	// 用图的话可以考虑BFS,DFS。思路就是把边界上的0通过BFS或DFS，都变成'#'。
	// 最后遍历整个矩阵，'O'变成'X'，而'#'变成'O'。
    void solve(vector<vector<char>>& board) {
        
    }
};