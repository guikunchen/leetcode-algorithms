#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(string& s : strs) {
        	string t = s;
        	sort(t.begin(), t.end());
        	m[t].push_back(s);
        }
        for(auto& item : m) {
        	ans.push_back(item.second);
        }
        return ans;
    }
};