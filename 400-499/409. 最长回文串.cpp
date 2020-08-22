// https://leetcode-cn.com/problems/longest-palindrome/
/*给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hm;
        for(auto c: s) hm[c]++;
        int count = 0;
        bool flag = false;// 回文串长度是单数还是双数
        for(pair<char, int> p: hm){
            int n = p.second;
            if(n & 1 == 1){
                count += n - 1;
                flag = true;
            }
            else{
                count += n;
            }
        }
        return flag? count + 1: count;
    }
};

