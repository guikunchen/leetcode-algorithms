
// https://leetcode-cn.com/problems/valid-palindrome/

// 求无向图从起点到终点的最短路径
class Solution{// 单向BFS
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        //加入所有节点，访问过一次，删除一个。
        unordered_set<string> s;
        for (auto &i : wordList) s.insert(i);

        queue<pair<string, int>> q;
        //加入beginword
        q.push({beginWord, 1});

        string tmp; //每个节点的字符
        int step;    //抵达该节点的step

        while ( !q.empty() ){
            if ( q.front().first == endWord){
                return (q.front().second);
            }
            tmp = q.front().first;
            step = q.front().second;
            q.pop();

            //寻找下一个单词了
            char ch;
            for (int i = 0; i < tmp.length(); i++){
                ch = tmp[i];
                for (char c = 'a'; c <= 'z'; c++){
                    //从'a'-'z'尝试一次
                    if ( ch == c) continue;
                    tmp[i] = c ;
                    //如果找到的到
                    if (  s.find(tmp) != s.end() ){
                        q.push({tmp, step+1});
                        s.erase(tmp) ; //删除该节点
                    }
                tmp[i] = ch; //复原
                }
               
            }
        }
        return 0;
    }
};

// 如下是双向BFS代码, 代码其实不复杂。相对于之前单向BFS，有如下改进

// 使用两个set，分别从start和end两头开始BFS
// 每次选择较小的set开始BFS, 也就是将小的作为start，大的作为end
// 如果end中能找到start，就结束
// 否则，在访问set中加入访问记录，并加入到tmp中，作为子节点。

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end() ) return 0;
        // 初始化起始和终点
        unordered_set<string> beginSet, endSet, tmp, visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int len = 1;

        while (!beginSet.empty() && !endSet.empty()){
            if (beginSet.size() > endSet.size()){
                tmp = beginSet;
                beginSet = endSet;
                endSet = tmp;
            }
            tmp.clear();
            for ( string word : beginSet){
                for (int i = 0; i < word.size(); i++){
                    char old = word[i];
                    for ( char c = 'a'; c <= 'z'; c++){
                        if ( old == c) continue;
                        word[i] = c;
                        if (endSet.find(word) != endSet.end()){
                            return len+1;
                        }
                        if (visited.find(word) == visited.end() && dict.find(word) != dict.end()){
                            tmp.insert(word);
                            visited.insert(word);
                        }
                    }
                    word[i] = old;
                }
            }
            beginSet = tmp;
            len++;
        }
        return 0;
    }
};