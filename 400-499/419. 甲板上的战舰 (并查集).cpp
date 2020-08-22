// https://leetcode-cn.com/problems/battleships-in-a-board/

class Solution {// 求连通子图的数量，一般BFS或DFS
public:// 解法：扫描到X时，如果上方或者左方也是X，则不计数，否则计数加1。
    int countBattleships(vector<vector<char>>& board) {
        int nCount = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X' ||
                        j > 0 && board[i][j - 1] == 'X')
                        continue;
                    ++nCount;
                }
            }
        }
        return nCount;
    }
};