#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/flip-game
/*你和朋友玩一个叫做「翻转游戏」的游戏，游戏规则：给定一个只有 + 和 - 的字符串。
你和朋友轮流将 连续 的两个 “++” 反转成 “-–”。
当一方无法进行有效的翻转时便意味着游戏结束，则另一方获胜。

请你写出一个函数，来计算出第一次翻转后，字符串所有的可能状态。
*/
class Solution {// 一次遍历
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        string temp;
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i-1]==s[i] && s[i]=='+')
            {
                temp = s;
                temp[i-1] = temp[i] = '-';
                ans.push_back(temp);
            }
        }
        return ans;
    }
};