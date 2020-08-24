#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/shortest-word-distance
/*给定一个字符串，对该字符串可以进行 “移位” 的操作，也就是将字符串中每个字母都变为其在字母表中后续的字母，比如：“abc” -> “bcd”。
这样，我们可以持续进行 “移位” 操作
输入：["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"]
输出：
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
解释：可以认为字母表首尾相接，所以 'z' 的后续为 'a'，
所以 ["az","ba"] 也满足 “移位” 操作规律。
*/
class Solution {// 都转成以a开头的字符串
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> m;
        string key;
        for(string& s : strings)
        {
            key = s;
            int dis = s[0]-'a';
            for(int i = 0; i < key.size(); ++i)
                key[i] = (key[i]-dis+26)%26;// 字母表首尾相接
            m[key].push_back(s);
        }
        vector<vector<string>> ans(m.size());
        int i = 0;
        for(auto it = m.begin(); it != m.end(); ++it)
            ans[i++] = it->second;
        return ans;
    }
};