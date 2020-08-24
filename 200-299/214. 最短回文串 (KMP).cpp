#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/shortest-palindrome/

// 用KMP算出前缀和后缀相等的长度，实际上就是求最左边的最长的回文串（可以省略），使步数最短
string shortestPalindrome(string s)
{
    int n = s.size();
    string rev(s);
    reverse(rev.begin(), rev.end());
    string s_new = s + "#" + rev;
    int n_new = s_new.size();
    vector<int> f(n_new, 0);
    for (int i = 1; i < n_new; i++) {
        int t = f[i - 1];
        while (t > 0 && s_new[i] != s_new[t])
            t = f[t - 1];
        if (s_new[i] == s_new[t])
            ++t;
        f[i] = t;// f[i] 是索引[0, i]的字符串前缀和后缀相同的最大长度
    }
    return rev.substr(0, n - f[n_new - 1]) + s;
}