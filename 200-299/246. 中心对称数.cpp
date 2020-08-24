#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/strobogrammatic-number
/*中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
请写一个函数来判断该数字是否是中心对称数，其输入将会以一个字符串的形式来表达数字。*/
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> m = {{'6','9'},{'9','6'},{'8','8'},{'1','1'},{'0','0'}};
        string rotate;
        for(char ch : num)
        {
            if(!m.count(ch))// 如果包括2 3这种数字，就一定不符合条件，不可以旋转
                return false;
            rotate = m[ch]+rotate;// 生成逆序
        }
        return rotate==num;
    }   
};