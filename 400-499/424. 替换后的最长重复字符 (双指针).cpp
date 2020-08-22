// https://leetcode-cn.com/problems/longest-repeating-character-replacement/
// 给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。
// 在执行上述操作后，找到包含重复字母的最长子串的长度。
class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26]={0};//建立字符->字符数量的映射
        
        int left=0,right=0,result=0,maxCount=0;
        
        while(right<s.size())
        {
            count[s[right]-'A']++;
            maxCount=max(maxCount,count[s[right]-'A']);//当前窗口内的最多字符的个数
            if(right-left+1-maxCount>k){//需要替换的字符个数就是当前窗口的大小减去窗口中数量最多的字符的数量
                count[s[left]-'A']--;//缩小窗口
                left++;
            }
            //当窗口内可替换的字符数小于等于k时，我们需要根据该窗口长度来确定是否更新result
            result=max(result,right-left+1);
            right++;
        }
        
        return result;
    }
};