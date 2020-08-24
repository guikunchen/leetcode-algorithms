#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/
// 给定一个字符串 s ，找出 至多 包含两个不同字符的最长子串 t 。
// 输入: "eceba" 输出: 3 解释: t 是 "ece"，长度为3。
// 输入: "ccaabbb" 输出: 5 解释: t 是 "aabbb"，长度为5。
// 滑动窗口
// 时间复杂度：O(n) 空间复杂度：O(n)
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> m;
        int cnt = 0;                // 不同字符个数
        int left = 0, right = 0;    // right指向的是窗口外的下一个字符
        int maxLen = 0;
        while(right < s.size()){
            if(m[s[right]] == 0)
                cnt ++;             // 出现新字符
            m[s[right++]]++;        // 计数+1并右移
            while(cnt > 2){         // 当窗口元素大于2，窗口缩小
                m[s[left]]--;       // 计数-1
                if(m[s[left]] == 0){
                    cnt--;         // 字符计数减为0
                }
                left++;// 窗口缩小
            }
            maxLen = max(maxLen, right - left); // 满足条件的窗口长度
        }
        return maxLen;
    }
};