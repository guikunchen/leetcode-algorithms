#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_set<char> used;
        vector<int> alphabets(26, 0);
        for(int i = 0; i < s.size(); i++) {
            alphabets[s[i] - 'a'] = i;
        }

        string ans;
        for(int i = 0; i < s.size(); i++) {
            if(used.count(s[i])) {// 已在前面用过
                continue;
            }
            // 小的字符"尽量"放前面（当前字符在后面有出现才能够去掉！！！）
            while(!ans.empty() && ans.back() > s[i] && alphabets[ans.back() - 'a'] > i) {
                used.erase(ans.back());
                ans.pop_back();
            }
            
            used.insert(s[i]);
            ans += s[i];
        }
        return ans;
    }
};