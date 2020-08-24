#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/shortest-word-distance-ii/
/*请设计一个类，使该类的构造函数能够接收一个单词列表。
然后再实现一个方法，该方法能够分别接收两个单词 word1 和 word2，并返回列表中这两个单词之间的最短距离。
您的方法将被以不同的参数调用 多次。*/
class WordDistance {
public:
    // 用数组存放每个word出现的所有索引
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }
 
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for (int i = 0; i < m[word1].size(); ++i) {
            for (int j = 0; j < m[word2].size(); ++j) {// 第二重循环可以改成二分查找，加快效率
                res = min(res, abs(m[word1][i] - m[word2][j]));
            }
        }
        return res;
    }
     
private:
    unordered_map<string, vector<int> > m;
};