#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/n-queens/
// 返回所有的解法
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        int* cols = new int[n];// cols[i]=j  表示[i][j]有一个皇后
        backtracking(n, 0, cols, ans);
        delete [] cols;
        return ans;
    }

    void backtracking(int n, int row, int* cols, vector<vector<string>>& ans) {
    	if (row == n) {
    		vector<string> solution;
            for (int i = 0; i < n; i++) {
                string str(n, '.');
                str[cols[i]] = 'Q';
                solution.push_back(str);
            }
            ans.push_back(solution);
    		return;
    	}

    	for (int col = 0; col < n; col++) {
    		cols[row] = col;
    		if (check(row, col, cols)) {
				backtracking(n, row + 1, cols, ans);
    		}
		}
    }

    bool check(int row, int col, int* cols) {
    	for (int i = 0; i < row; i++) {
    		if (cols[i] == col || row - i == abs(cols[i] - col)) { // 位于同一列或位于对角线
    			return false;
    		}
    	}
    	return true;
    }
};