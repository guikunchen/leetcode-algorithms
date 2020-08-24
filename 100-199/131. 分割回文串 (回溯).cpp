#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/palindrome-partitioning/

int len;
vector<string> str;
vector<vector<string>> partitionRes;

bool isPalindromic(string &s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        ++start;
        --end;
    }

    return true;
}

void backtrack(string &s, int pos) {
    if (pos == len) { 
        partitionRes.push_back(str);
        return; 
    }
    for (int i = pos; i < len; i++) {
        if (isPalindromic(s, pos, i)) {
            str.push_back(s.substr(pos, i - pos + 1));
            backtrack(s, i + 1);
            str.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    len = s.length();
    if (len == 0) return partitionRes;
    backtrack(s, 0);

    return partitionRes;
}