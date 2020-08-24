#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
/*给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
示例 1：

输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //特殊情况直接排除
        if(s.empty() || words.empty()) return {};
        
        //存放结果的数组
        vector<int> result;
        
        //单词数组中的单词的大小，个数，以及总长度
        int one_word = words[0].size();
        int word_num = words.size();
        int all_len = one_word * word_num;
        
        //建立单词->单词个数的映射
        unordered_map<string,int> m1;
        for(const auto& w:words) m1[w]++;
        
        for(int i=0; i<one_word; ++i) {
            //left和rigth表示窗口的左右边界，count用来统计匹配的单词个数
            int left = i, right = i, count = 0;
            
            unordered_map<string,int> m2;
            
            //开始滑动窗口
            while(right + one_word <= s.size()) {
                //从s中提取一个单词拷贝到w
                string w = s.substr(right,one_word);
                right += one_word;//窗口右边界右移一个单词的长度
                
                if(m1.count(w) == 0) {//此单词不在words中，表示匹配不成功,然后重置单词个数、窗口边界、以及m2
                    count = 0;
                    left = right;
                    m2.clear();
                }
                else {//该单词匹配成功，添加到m2中
                    m2[w]++;
                    count++;
                    while(m2.at(w) > m1.at(w)) {//一个单词匹配多次，需要缩小窗口，也就是left右移
                        string t_w = s.substr(left,one_word);
                        count--;
                        m2[t_w]--;
                        left += one_word;
                    }
                    if(count == word_num) result.push_back(left);
                }
            }
        }
        return result;
    }
};