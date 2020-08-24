#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/alien-dictionary
/*现有一种使用字母的全新语言，这门语言的字母顺序与英语顺序不同。

假设，您并不知道其中字母之间的先后顺序。
但是，会收到词典中获得一个 不为空的 单词列表。
因为是从词典中获得的，所以该单词列表内的单词已经 按这门新语言的字母顺序进行了排序。

您需要根据这个输入的列表，还原出此语言中已知的字母顺序。

示例 1：
输入:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
输出: "wertf"

示例 2：
输入:
[
  "z",
  "x"
]
输出: "zx"
*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> allchar;
        for(string& w : words) {// 记下所有的字符
            for(char ch : w)
                allchar.insert(ch);
        }
        unordered_map<char,int> indegree;// 存放入度
        unordered_map<char,unordered_set<char>> graph;
        int n1, n2, n;
        for(int i = 1, j; i < words.size(); ++i)
        {   
            if(words[i-1] == words[i])
                continue;
            n1 = words[i-1].size();
            n2 = words[i].size();
            n = min(n1, n2);
            for(j = 0; j < n; ++j)
            {
                if(words[i-1][j] != words[i][j]) { //不相等的第一个构成有向图的边
                    if(!graph.count(words[i-1][j]) || !graph[words[i-1][j]].count(words[i][j]))
                    {   //防止重复添加同一条边 "za","zb","ca","cb"
                        graph[words[i-1][j]].insert(words[i][j]);
                        indegree[words[i][j]]++;
                        indegree[words[i-1][j]] += 0;
                    }
                    break;
                }
            }
            if(j == n && n1 > n2)
                return "";//前面相等，前者长不行
        }
        queue<char> q;
        for(auto it = indegree.begin(); it != indegree.end(); ++it) {
            if(it->second == 0)//入度为0的入队
                q.push(it->first);
        }
        string ans;
        while(!q.empty()) {
            char ch = q.front();
            allchar.erase(ch);
            q.pop();
            ans += ch;
            for(auto it = graph[ch].begin(); it != graph[ch].end(); ++it)
            {
                if(--indegree[*it] == 0)
                    q.push(*it);
            }
        }
        if(ans.size() != indegree.size())// 不是所有被边连接的节点都被访问到
            return "";// 有环
        while(allchar.size()) {// 剩余字符随便放，拓扑排序的孤立节点
            ans += *allchar.begin();
            allchar.erase(allchar.begin());
        }
        return ans;
    }
};