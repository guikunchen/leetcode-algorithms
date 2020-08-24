#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/shortest-word-distance
/*给定一个单词列表和两个单词 word1 和 word2，返回列表中这两个单词之间的最短距离。

示例:
假设 words = ["practice", "makes", "perfect", "coding", "makes"]
输入: word1 = “coding”, word2 = “practice”
输出: 3
输入: word1 = "makes", word2 = "coding"
输出: 1

注意:
你可以假设 word1 不等于 word2, 并且 word1 和 word2 都在列表里。*/
class Solution {
public:
	// 遍历字符串，记录最后一次出现的位置即可，然后更新差距最小的。
    int shortestDistance(vector<string>& words, string word1, string word2) {
       if (words.size() < 2) {
            return -1;
        }
        int i1 = -1, i2 = -1;
        int minDistance = INT_MAX;
        for(int i = 0; i < words.size(); ++i) {
        	if(words[i] == word1) {
        		i1 = i;
        		if(i1 != -1 && i2 != -1 && i1 - i2 < minDistance) {
        			minDistance = i1 - i2;
        		}
        	} else if(words[i] == word2) {
				i2 = i;
        		if(i1 != -1 && i2 != -1 && i2 - i1 + 1 < minDistance) {
        			minDistance = i2 - i1;
        		}
        	}
        }
        return minDistance;
    }
};