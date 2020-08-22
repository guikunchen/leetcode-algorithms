// https://leetcode-cn.com/problems/number-of-segments-in-a-string/

class Solution {// 这里的单词指的是连续的不是空格的字符“（英文题目里叫segment而非word）
public:// 因此，题目的单词并非只有我们认为的单词，像 "Hello"  ","  ",,,," 也都算单词。
    int countSegments(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                count++;
            }
        }
        return count;
    }
};