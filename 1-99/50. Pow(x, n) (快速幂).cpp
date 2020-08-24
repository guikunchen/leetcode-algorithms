#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/powx-n/

class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N >> 1);
        return N & 1 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;// INT_MIN 不能直接加负号，所以要用long long
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

class Solution {
public:
    // N可以按位划分为1 2 4 8 16，对应着x^1 x^2 x^4
    double quickMul(double x, long long N) {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N & 1 == 1) {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N >>= 1;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};