#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/valid-sudoku/
/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	vector<vector<int>> rows(9, vector<int>(9, 0));// 第i行，某个数字是否出现过，其实里面用bool就可以了
    	vector<vector<int>> columns(9, vector<int>(9, 0));
    	vector<vector<int>> boxes(9, vector<int>(9, 0));
        
        for(int i = 0; i < 9; i++) {
        	for(int j = 0; j < 9; j++) {
        		if(board[i][j] == '.') {
        			continue;
        		}
        		int num = board[i][j] - '1';
        		int boxes_index = (i / 3) * 3 + j / 3;
        		if(rows[i][num] > 0 || columns[j][num] > 0 || boxes[boxes_index][num] > 0) return false;
        		rows[i][num] = columns[j][num] = boxes[boxes_index][num] = 1;
        	}
        }
        return true;
    }
};