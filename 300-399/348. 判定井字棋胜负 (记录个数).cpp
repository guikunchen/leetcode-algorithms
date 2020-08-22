#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/design-tic-tac-toe/
/*请在 n × n 的棋盘上，实现一个判定井字棋（Tic-Tac-Toe）胜负的神器，判断每一次玩家落子后，是否有胜出的玩家。
在这个井字棋游戏中，会有 2 名玩家，他们将轮流在棋盘上放置自己的棋子。
在实现这个判定器的过程中，你可以假设以下这些规则一定成立：
  1 . 每一步棋都是在棋盘内的，并且只能被放置在一个空的格子里；
  2 . 一旦游戏中有一名玩家胜出的话，游戏将不能再继续；
  3 . 一个玩家如果在同一行、同一列或者同一斜对角线上都放置了自己的棋子，那么他便获得胜利。
示例:
给定棋盘边长 n = 3, 玩家 1 的棋子符号是 "X"，玩家 2 的棋子符号是 "O"。

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> 函数返回 0 (此时，暂时没有玩家赢得这场对决)
|X| | |
| | | |    // 玩家 1 在 (0, 0) 落子。
| | | |

toe.move(0, 2, 2); -> 函数返回 0 (暂时没有玩家赢得本场比赛)
|X| |O|
| | | |    // 玩家 2 在 (0, 2) 落子。
| | | |

toe.move(2, 2, 1); -> 函数返回 0 (暂时没有玩家赢得比赛)
|X| |O|
| | | |    // 玩家 1 在 (2, 2) 落子。
| | |X|

toe.move(1, 1, 2); -> 函数返回 0 (暂没有玩家赢得比赛)
|X| |O|
| |O| |    // 玩家 2 在 (1, 1) 落子。
| | |X|

toe.move(2, 0, 1); -> 函数返回 0 (暂无玩家赢得比赛)
|X| |O|
| |O| |    // 玩家 1 在 (2, 0) 落子。
|X| |X|

toe.move(1, 0, 2); -> 函数返回 0 (没有玩家赢得比赛)
|X| |O|
|O|O| |    // 玩家 2 在 (1, 0) 落子.
|X| |X|

toe.move(2, 1, 1); -> 函数返回 1 (此时，玩家 1 赢得了该场比赛)
|X| |O|
|O|O| |    // 玩家 1 在 (2, 1) 落子。
|X|X|X|
 
进阶:
您有没有可能将每一步的 move() 操作优化到比 O(n^2) 更快吗?*/

class TicTacToe {// 记录两个人，每行、列、2对角线的棋子个数
	vector<vector<int>> R;
    vector<vector<int>> C;
    vector<int> X45;//45度对角线
    vector<int> X135;//135度对角线
    int N;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
    	N = n;
    	R = vector<vector<int>> (2,vector<int>(n,0));
    	C = vector<vector<int>> (2,vector<int>(n,0));
    	X45 = vector<int> (2,0);//45度对角线
    	X135 = vector<int> (2,0);//135度对角线
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
    	if(row == col)
    		X45[player-1]++;
    	if(row+col == N-1)
    		X135[player-1]++;
    	R[player-1][row]++;
    	C[player-1][col]++;
    	if(R[player-1][row]==N || C[player-1][col]==N 
    		|| X45[player-1]==N || X135[player-1]==N)
    		return player;
    	return 0;
    }
};