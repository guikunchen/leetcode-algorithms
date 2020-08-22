#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/integer-break/

class Solution {// 这题就是剪绳子，贪心算的最快，也可以动态规划
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int quotient = n / 3;
        int remainder = n % 3;
        if (remainder == 0) {
            return (int)pow(3, quotient);
        } else if (remainder == 1) {
            return (int)pow(3, quotient - 1) * 4;
        } else {
            return (int)pow(3, quotient) * 2;
        }
    }
};