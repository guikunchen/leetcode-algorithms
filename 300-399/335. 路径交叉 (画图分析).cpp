#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/self-crossing/

// https://leetcode-cn.com/problems/self-crossing/solution/yi-bu-yi-bu-fen-xi-by-lzh_yves/
class Solution {// 画图讨论三种相交模型
public:
    bool isSelfCrossing(vector<int>& x) {
        int x_size=x.size();
        for (int i=3;i<x_size;++i)
        {
            if (i>=3 && x.at(i-1)<=x.at(i-3) && x.at(i)>=x.at(i-2))
                return true;
            if (i>=4 && x.at(i-3)==x.at(i-1) && x.at(i)+x.at(i-4)>=x.at(i-2))
                return true;
            if (i>=5 && x.at(i)+x.at(i-4)>=x.at(i-2) && x.at(i-1)+x.at(i-5)>=x.at(i-3) && x.at(i-2)>x.at(i-4) && x.at(i-3)>x.at(i-1))
                return true;
        }
        return false;
    }
};