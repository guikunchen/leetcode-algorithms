#include<iostream>// 76、3、438题
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> subs;
        int n = s.length(), ans = 0;
        for(int i = 0, j = 0; j < n; j++){
            if(subs.count(s[j])){
                i = max(i, subs[s[j]] + 1);
            }
            ans = max(ans, j - i + 1);
            subs[s[j]] = j;
        }
        return ans;
    }
};

// 滑窗法，map记录元素index
// map.insert()，如果原本有key则插入失败