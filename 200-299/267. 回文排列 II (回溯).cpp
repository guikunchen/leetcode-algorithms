#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/palindrome-permutation-ii/
/*给定一个字符串 s ，返回其通过重新排列组合后所有可能的回文字符串，并去除重复的组合。
如不能形成任何回文排列时，则返回一个空列表。
*/
class Solution {
    vector<string> ans;
    int n;
public:
    vector<string> generatePalindromes(string s) {
        vector<int> count(128,0);
        n = s.size();
        for(char ch : s)
            count[ch]++;
        int odd = 0, idx;// idx记录奇数数量字符的索引
        for(int i = 0; i < 128; ++i) {
            if(count[i]&1) {
                odd++;
                idx = i;
            }
            if(odd > 1)// 不能排列成回文字符串
                return {};
        }
        s = odd ? string(1, idx) : "";// 奇数字符要放在最中间
        odd ? count[idx]-- : 0;//奇数的字符-1
        backtrack(count,s);
        return ans;
    }

    void backtrack(vector<int>& count, string s)
    {
        if(s.size()==n)
        {
            ans.push_back(s);//长度够了返回
            return;
        }
        for(int i = 0; i < 128; ++i) {
            if(count[i]) {
                count[i] -= 2;//两侧加上相同字符，还是回文
                backtrack(count, char(i)+s+char(i));
                count[i] += 2;//回溯
            }
        }
    }
};