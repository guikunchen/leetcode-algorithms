// https://leetcode-cn.com/problems/repeated-substring-pattern/

class Solution {
public:
    // 如果您的字符串S包含一个重复的子字符串，那么这意味着您可以多次“移位和换行”您的字符串，并使其与原始字符串匹配。
    // 例如:abcabc
    // 移位一次:cabcab
    // 移位两次:bcabca
    // 移位三次:abcabc 和原来的一样，所以存在
    // 为了避免这种无用的环绕，可以创建一个新的字符串str,它等于原来的字符串S再加上S自身，这样其实就包含了所有移动的字符串。
    // abcabcabcabc
    // 左移一次就是bcabca，左移6次（长度）就是abcabc
    // 因此如果左移[1, 5]次中能找到一个和原来字符串相同的，就代表有重复子串
    bool repeatedSubstringPattern(string s) {
        // str1.find(str2);    //从str1[0]开始查找str2，返回str2中首个字符在str1中的地址
        // str1.find(str2,5);  //从str1[5]开始查找str2
        return (s+s).find(s,1)!=s.size();
    }
};