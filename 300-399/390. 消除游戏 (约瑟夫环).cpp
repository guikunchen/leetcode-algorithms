// https://leetcode-cn.com/problems/elimination-game/

// 画图分析 约瑟夫环问题的变种  最关键的是找到映射关系！
class Solution {
public:
    int lastRemaining(int n) {
        return n==1 ? 1 : 2*(n/2+1-lastRemaining(n/2));
    }
};