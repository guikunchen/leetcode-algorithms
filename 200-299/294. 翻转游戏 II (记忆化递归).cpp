#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/flip-game-ii
/*你和朋友玩一个叫做「翻转游戏」的游戏，
游戏规则：给定一个只有 + 和 - 的字符串。
你和朋友轮流将 连续 的两个 "++" 反转成 "--"。
当一方无法进行有效的翻转时便意味着游戏结束，则另一方获胜。

请你写出一个函数来判定起始玩家是否存在必胜的方案。
*/
class Solution {// 记忆化递归
    unordered_map<string,bool> m;
public:
    bool canWin(string s) {
        if(s.size() <= 1) return false;
        if(m.count(s)) return m[s];
        string t;
        for(int i = 0; i < s.size()-1; ++i) {
            if(s[i]=='+' && s[i+1]=='+') {
                t = s;
                t[i]=t[i+1]='-';
                if(!canWin(t)) {// 换了一次后没法赢，说明没换之前这个字符串一定赢
                    m[s] = true;
                    return true;
                }
            }
        }
        // 没有一次是，翻转一次后的字符串必输的，也就是这次翻转后对方一定赢
        m[s] = false;
        return false;
    }
};