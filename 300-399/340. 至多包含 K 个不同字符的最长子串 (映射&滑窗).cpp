#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters

class Solution {// 滑动窗口[j ,i]
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
    	unordered_map<char,int> m;
    	int maxlen = 0;
    	for(int i = 0, j = 0; i < s.size(); ++i) {
    		if(m.size() <= k)
    			m[s[i]]++;
    		while(m.size()>k) {// 根据j的位置不断缩小窗口
    			if(--m[s[j]] == 0)
    				m.erase(s[j]);
    			j++;
    		}
    		maxlen = max(maxlen, i-j+1);
    	}
    	return maxlen;
    }
};