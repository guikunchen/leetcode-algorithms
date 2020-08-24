// https://leetcode-cn.com/problems/valid-anagram/

class Solution {
public:
    // 输入只有二十六个小写字母，所以可以用字母表
    bool isAnagram(string s, string t) {
        vector<int> alphabet(26, 0);
        for(int i = 0; i < s.size(); i++){
            alphabet[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            alphabet[t[i] - 'a']--;
        }
        for(int n : alphabet){
            if(n != 0) return false;
        }
        return true;
    }


    // 做一点小优化，两个长度不等可以直接返回false

    // 也可以在遍历t时判断减完是否小于0，小于0（t比s多了一个这个字符）可直接返回false

    // 如果输入的是Unicode，则需要用哈希表，不能用固定长度的表。

};