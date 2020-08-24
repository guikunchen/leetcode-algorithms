#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/shortest-word-distance-iii/
/*给定一个单词列表和两个单词 word1 和 word2，返回列表中这两个单词之间的最短距离。
word1 和 word2 是有可能相同的，并且它们将分别表示为列表中两个独立的单词。*/
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1, minDistance = INT_MAX;
        bool same = word1 == word2;
        for(int i = 0; i < words.size(); ++i) {
            if(same && words[i] == word1) {// 相同的情况
                if(p1 != -1)
                    minDistance = min(minDistance, i-p1);
                p1 = i;
                continue;
            }
            //不同的情况
            if(words[i] == word1)
                p1 = i;
            if(words[i] == word2)
                p2 = i;
            if(p1 != -1 && p2 != -1)
                minDistance = min(minDistance, abs(p1-p2));
        }
        return minDistance;
    }
};