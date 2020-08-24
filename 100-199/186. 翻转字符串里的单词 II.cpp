#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/reverse-words-in-a-string-ii
/*给定一个字符串，逐个翻转字符串中的每个单词。

示例：
输入: ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
输出: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]

注意：
单词的定义是不包含空格的一系列字符
输入字符串中不会包含前置或尾随的空格
单词与单词之间永远是以单个空格隔开的

进阶：使用 O(1) 额外空间复杂度的原地解法。*/
// 该题假设开头和结尾没有空格，而且单词之间只有一个空格。不需要这些假设也是可以的，就是代码会比较复杂。
// 先反转每个单词，然后从头到尾反转，就是需要的答案
// eht yks si eulb
// blue is sky the
class Solution {
public:
    void reverseWords(string &s) {
        int left = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, left, i - 1);
                left = i + 1;
            }
        }
        reverse(s, 0, s.size() - 1);
    }
    void reverse(string &s, int left, int right) {
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            ++left; --right;
        }
    }
};