#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/word-pattern-ii
/*给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false. 

可以用回溯法来判断每一种情况，用哈希表建立模式字符和单词之间的映射，
还需要用变量p和r来记录当前递归到的模式字符和单词串的位置，
在递归函数中，如果p和r分别等于模式字符串和单词字符串的长度，
说明此时匹配成功结束了，返回ture，反之如果一个达到了而另一个没有，说明匹配失败了，返回false。
*/
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        set<string> s;
        return backtrack(pattern, 0, str, 0, m, s);
    }
    bool backtrack(string &pattern, int p, string &str, int r, unordered_map<char, string> &m, set<string> &s) {
        if (p == pattern.size() && r == str.size()) return true;
        if (p == pattern.size() || r == str.size()) return false;
        char c = pattern[p];
        for (int i = r; i < str.size(); ++i) {
            string t = str.substr(r, i - r + 1);
            if (m.count(c) && m[c] == t) {// 已建立映射且相同
                if (backtrack(pattern, p + 1, str, i + 1, m, s)) return true;
            } else if (!m.count(c)) {// 没有建立起映射
                if (s.count(t)) continue;// t已被其他字符映射
                m[c] = t;// 建立映射
                s.insert(t);// 标志已建立映射
                if (backtrack(pattern, p + 1, str, i + 1, m, s)) return true;
                m.erase(c);// 删除映射
                s.erase(t);// 删除映射标记
            }
        }
        return false;
    }
};