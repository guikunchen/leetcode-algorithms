// https://leetcode-cn.com/problems/valid-word-abbreviation/

// 给一个 非空 字符串 s 和一个单词缩写 abbr ，判断这个缩写是否可以是给定单词的缩写。

// 等效长度一致，数字不能有前导零
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
      int i = 0, n = 0, j = 0;
      while(i<word.size() && j < abbr.size()) {
        n = 0;
        if(isdigit(abbr[j])) {   
            if(abbr[j]=='0')//"a","01"
                return false;
            while(j < abbr.size() && isdigit(abbr[j]))
                n = n*10+abbr[j++]-'0';
        }
        i += n;
        if(i<word.size() && j<abbr.size() && word[i] != abbr[j])
          return false;
        else if((i<word.size()&&j>=abbr.size())||(i>=word.size()&&j<abbr.size()))
          return false;
        else if(i==word.size() && j==abbr.size())
                return true;//这里加一条，可能以数字结尾，下面++，出了循环，最后条件不成立
        i++,j++;
      }
      return i==word.size() && j==abbr.size();
    }
};