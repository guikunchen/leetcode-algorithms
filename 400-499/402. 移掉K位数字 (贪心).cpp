// https://leetcode-cn.com/problems/remove-k-digits/
/*给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。*/

class Solution {// 贪心，前一个比较大，能删则删
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k) return "0";// 直接删完了
        
        string ans;
        int count = 0;
        for(int i = 0; i < num.size(); i++) {
            while(!ans.empty() && num[i] < ans.back() && count < k) {
                count++;
                ans.pop_back();
            }
            ans += num[i];
        }
        int zero = 0;// 前导0
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == '0') zero++;
            else break;
        }
        return zero == ans.size() ? "0" : ans.substr(zero, num.size() - k - zero);
    }
};