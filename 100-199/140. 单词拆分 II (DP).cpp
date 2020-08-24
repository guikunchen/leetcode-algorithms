#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/word-break-ii/
/*给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
] */
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        int len = s.length();

        Set<String> set = new HashSet<>(wordDict);

        /*
        dp 处理，dp[i] 表示 [0, i] 是否能够 通过分割 或 不分割 使得处理后的字符串存在于字典中
        比如  s = catsand, wordDict = ["cat", "sand"]
        我们可以通过分割成 cat 和 sand 使得分割后的字符串存在于字典中, dp[i] = true;
        比如  s = catsand, wordDict = ["catsand"]
        我们可以不分割就使得原字符串存在于字典中, dp[i] = true;
        比如  s = catsand, wordDict = ["cats"]
        我们无论分割还是不分割都无法使得字符串都存在于字典中, dp[i] = false;
        */
        boolean[] dp = new boolean[len + 1];
        dp[0] = true;
        for(int i = 1; i <= len; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && set.contains(s.substring(j, i))){
                    dp[i] = true;
                }
            }
        }
        //原字符串 s 无法处理成字典中的字符串
        if(!dp[len]){
            return new ArrayList<>();
        }
        List<String>[] strs = new List[len + 1];
        for(int i = 0; i <= len; i++){
            strs[i] = new ArrayList<>();
        }        
        for(int i = 1; i <= len; i++){
            if(!dp[i]){
                continue;
            }
            for(int j = 0; j < i; j++){
                if(!dp[j]){
                    continue;
                }
                String str = s.substring(j, i);
                if(!set.contains(str)){
                    continue;
                }
                if(strs[j].isEmpty()){
                    strs[i].add(str);
                }else{
                    for(String ss : strs[j]){
                        strs[i].add(new StringBuilder(ss).append(" ").append(str).toString());
                    }
                }
            }
        }
        return strs[len];
    }
}