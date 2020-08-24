#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/excel-sheet-column-number/
// 实际上就是26进制转10进制
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            res = res * 26 + (s[i] - 'A' + 1);
        }
        return res;
    }
};