#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/word-search-ii/ 第一题79
/*给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。*/

class TrieNode{
public:
    bool is_word;
    string str;
    vector<TrieNode*> next;
    
    TrieNode(){
        is_word = false;
        next = vector<TrieNode*>(26, nullptr);
    }
};

class Solution {
public:
    TrieNode* root;
    int n, m;
    vector<string> ans;
    vector<vector<char>> data;// 图
    unordered_set<string> tmp;
    vector<vector<bool>> vis;
    int dx[4] = {-1, 1, 0, 0};// 左 右 下 上
    int dy[4] = {0, 0, -1, 1};
    
    void add(string& word) {// 插入到前缀树
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur -> next[c - 'a'] == nullptr) cur -> next[c - 'a'] = nextw TrieNode();
            cur = cur -> next[c - 'a'];
        }
        cur -> is_word = true;
        cur -> str = word;
    }
    
    void backtrack(int x, int y, TrieNode* cur) {
        if (cur -> is_word) {// 到达一个单词
            if (!tmp.count(cur -> str)) {// 没添加到答案里
                ans.push_back(cur -> str);
                tmp.insert(cur -> str);
            }
        }
        for (int i = 0; i < 4; i ++) {
                int xx = dx[i] + x, yy = dy[i] + y;
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy]) continue;// 越界或已访问
                if (cur -> next[data[xx][yy] - 'a']) {// 沿着前缀树回溯
                    vis[xx][yy] = true;
                    backtrack(xx, yy, cur -> next[data[xx][yy] - 'a']);
                    vis[xx][yy] = false;
                }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        data = board;
        ans = vector<string>();
        for (auto x : words) add(x);// 添加到前缀树
        n = board.size();
        if (n == 0) return {};
        m = board[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));// 是否访问过
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (root -> next[board[i][j] - 'a']) {// 存在以其开头的单词
                    vis[i][j] = true;// 标记已访问
                    backtrack(i, j, root -> next[board[i][j] - 'a']);
                    vis[i][j] = false;
                }
            }
        }
        return ans;
    }
};