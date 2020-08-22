#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.empty() || s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int numG = 0, numS = 0;
        while(numG < g.size() && numS < s.size()) {
            if(g[numG] <= s[numS]) {
                numG++;
            }
            numS++;
        }
        return numG;
    }
};