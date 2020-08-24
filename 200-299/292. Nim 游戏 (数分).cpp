#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/nim-game/
class Solution {
public:
    bool canWinNim(int n) {// 不能是4的倍数，4的倍数一定输
        return (n & 3) != 0;
    }
};