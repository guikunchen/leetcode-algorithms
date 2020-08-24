#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/n-queens-ii/
// 返回所有解法的个数
class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        int* cols = new int[n];// cols[i]=j  表示[i][j]有一个皇后
        backtracking(n, 0, cols, result);
        delete [] cols;
        return result;
    }

    void backtracking(int n, int row, int* cols, int& result) {
    	if(row == n) {
    		result++;
    		return;
    	}

    	for (int col = 0; col < n; col++) {
    		cols[row] = col;
    		if (check(row, col, cols)) {
				backtracking(n, row + 1, cols, result);
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