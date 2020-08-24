#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/unique-word-abbreviation
/*一个单词的缩写需要遵循 <起始字母><中间字母数><结尾字母> 这样的格式。
给定 dictionary = [ "deer", "door", "cake", "card" ]
isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(string s : dictionary){
            mp[abbrivate(s)].push_back(s);
        }
    }
    string abbrivate(string s){
        int len = s.size();
        return len<=2 ? s : s[0] + to_string(len-2) + s[len-1];
    }
    bool isUnique(string word) {
        // 单词长度小于等于二 或 字典里有这个缩写但是只有word 或 字典里根本没这个缩写
        return word.size() <= 2
            || (mp[abbrivate(word)].size() == 1 && mp[abbrivate(word)].find(word) != mp[abbrivate(word)].end()) 
            || mp[abbrivate(word)].empty();
    }
private: unordered_map<string, unordered_set<string>> mp;
// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
};