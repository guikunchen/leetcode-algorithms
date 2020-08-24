#include<iostream>
#include<vector>
#include<set>
using namespace std;

// 动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int len = 0; len < n; ++len) {// 从短字符字串到长
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                if (len == 0) {// 为了计算方便，实际长度要加一
                    dp[i][j] = 1;
                }
                else if (len == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && len + 1 > ans.size()) {
                    ans = s.substr(i, len + 1);
                }
            }
        }
        return ans;
    }
};

// 中心扩展法
class Solution {
public:
    string longestPalindrome(string s) {
    	if(s.empty()) return "";
        int start = 0, length = 0;
        for(int i=0; i<s.length(); i++){
        	int len1 = expandFromCenter(s, i, i);
        	int len2 = expandFromCenter(s, i, i+1);
        	int len = max(len1, len2);
        	if(length<len){
        		start = i - (len-1)/2;
        		length = len;
			}
		}
        return s.substr(start, length);
    }
	int expandFromCenter(string s, int start, int end){
		int left = start, right = end;
		while(left>=0 && right<s.length() && s[left]==s[right]){
			left--;
			right++;
		}
		return right-left-1;
	}
};

// 回环有两种center   一种"abba"，一种"aboba"。