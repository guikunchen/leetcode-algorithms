#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n != 0) {
            sum++;
            n &= (n - 1);// 会把二进制最右边的1变成0
        }
        return sum;
    }
};