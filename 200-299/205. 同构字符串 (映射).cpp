// https://leetcode-cn.com/problems/isomorphic-strings/

/*
给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMap;
        unordered_set<char> usedCh;
        for(int i = 0; i < s.size(); i++){
            if(sMap.find(s[i]) != sMap.end() && sMap[s[i]] != t[i]) return false;// 已建立映射关系，检查
            if(sMap.find(s[i]) == sMap.end() && usedCh.find(t[i]) != usedCh.end()) return false;// 建立新的映射关系失败
            sMap[s[i]] = t[i];
            usedCh.insert(t[i]);// 建立了一个映射关系，用掉了一个字符
        }
        return true;
    }
};

// 题解很多人写两个map
// 其实用一个map和一个set就可以了，我的侧重点在于建立新的映射关系