#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/house-robber-iii/ 第二题213 第一题198
// 可以跟3的幂一样，用底数来计算

class Solution {// 4的特殊之处在于只有一个1，且这个1在偶数索引
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num & 0xaaaaaaaa) == 0;
    }
};