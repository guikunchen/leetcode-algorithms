#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/sudoku-solver/

class Solution {
public:
    // 回溯 + bitmap
    void solveSudoku(vector<vector<char>>& board) 
    {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt = 0;// 还需要填的棋子的个数
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        dfs(board, cnt);
    }

    bool dfs(vector<vector<char>>& board, int cnt)
    {
        if (cnt == 0) return true;//递归结束条件

        auto next = getNext(board);// 每次都使用 getNext() 选择能填的数字最少的格子开始填，这样填错的概率最小，回溯次数也会变少

        auto bits = getPossibleStatus(next[0], next[1]);//找出这个坐标(i,j)可以填入的数字
        if(bits.count()==0) return false;

        for (int n = 0; n < bits.size(); n++)
        {
            if (!bits.test(n)) continue;
            fillNum(next[0], next[1], n, true);//更新存储状态
            board[next[0]][next[1]] = n + '1';

            if (dfs(board, cnt - 1)) return true;
            fillNum(next[0], next[1], n, false);//撤销上一步的存储状态
            board[next[0]][next[1]] = '.';
        }
        return false;
    }

    vector<int> getNext(vector<vector<char>>& board)
    {
        vector<int> ret;
        int minCnt = 10;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j);
                if (cur.count() >= minCnt) continue;
                ret = { i, j };
                minCnt = cur.count();
            }
        }
        return ret;
    }

    bitset<9> getPossibleStatus(int x, int y)
    {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    void fillNum(int x, int y, int n, bool fillFlag)
    {
        rows[x][n] = (fillFlag) ? (1) : (0);
        cols[y][n] = (fillFlag) ? (1) : (0);
        cells[x/3][y/3][n] = (fillFlag) ? (1): (0);
    }
private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
};