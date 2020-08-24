#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int len = 0;
        while(i >= 0 && s[i] == ' ') {
            i--;
        }
        while(i >= 0 && s[i] != ' ') {
            i--;
            len++;
        }
        return len;
    }
};