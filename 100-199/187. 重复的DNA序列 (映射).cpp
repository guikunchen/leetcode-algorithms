#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/repeated-dna-sequences/

// 用set或者map记录都可以
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> ans;
        int n = s.size();
        for (int i = 0; i + 10 <= n; i ++) {
            string t = s.substr(i, 10);
            if (mp[t] == 1) ans.push_back(t);
            mp[t] ++;
        }
        return ans;
    }
};