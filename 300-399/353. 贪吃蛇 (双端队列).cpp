#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/design-snake-game
/*起初时，蛇在左上角的 (0, 0) 位置，身体长度为 1 个单位。
你将会被给出一个 (行, 列) 形式的食物位置序列。当蛇吃到食物时，身子的长度会增加 1 个单位，得分也会 +1。
食物不会同时出现，会按列表的顺序逐一显示在屏幕上。比方讲，第一个食物被蛇吃掉后，第二个食物才会出现。
当一个食物在屏幕上出现时，它被保证不能出现在被蛇身体占据的格子里。
对于每个 move() 操作，你需要返回当前得分或 -1（表示蛇与自己身体或墙相撞，意味游戏结束）。
示例：
给定 width = 3, height = 2, 食物序列为 food = [[1,2],[0,1]]。*/

class SnakeGame {
    vector<vector<int>> food;
    int m, n, indexOfFood = 0, score = 0;
    int x = 0, y = 0;
    unordered_map<string, vector<int>> dir;
    deque<pair<int,int>> body;
    set<pair<int,int>> body_set;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->food = food;
        n = width;
        m = height;
        dir["R"] = {0,1};
        dir["D"] = {1,0};
        dir["U"] = {-1,0};
        dir["L"] = {0,-1};
        body.push_back({0,0});
        body_set.insert({0,0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        x += dir[direction][0];
        y += dir[direction][1];
        if(!(x>=0 && x<m && y>=0 && y<n)) 
            return -1;//出界
        if(indexOfFood < food.size() && x == food[indexOfFood][0] && y == food[indexOfFood][1]) {//吃到食物
            body.push_front({x, y});//头部加上
            body_set.insert({x, y});
            indexOfFood++;
            score++;
        }
        else {// 没吃到
            body_set.erase(body.back());//删除尾巴
            body.pop_back();//删除尾巴
            body.push_front({x, y});//加入头部
            if(body_set.count({x,y}))//撞身体了
                return -1;
            body_set.insert({x,y});//头部加入集合
        }
        return score;
    }
};