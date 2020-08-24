#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/implement-strstr/

class Solution {
public:
    int (*dp)[256];

    void KMP(string patten) {
        int M = patten.size();
        dp = new int[M][256];
        memset(dp[0], 0, sizeof(int) * 256);
        dp[0][patten[0]] = 1;
        int old = 0;
        for(int i = 1; i < M; i++) {
            for(int j = 0; j < 256; j++) {
                if(j == patten[i]) {
                    dp[i][j] = i + 1;// 前进一步
                } else {
                    dp[i][j] = dp[old][j];// old是和i具有相同前缀的状态
                }
            }
            old = dp[old][patten[i]];
        }
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(haystack.size() < needle.size()) return -1;

        KMP(needle);
        int i = 0, j = 0;
        while(i < haystack.size() && j < needle.size()) {
            j = dp[j][haystack[i]];
            i++;
        }
        return j == needle.size() ? i - needle.size() : -1;
    }
};