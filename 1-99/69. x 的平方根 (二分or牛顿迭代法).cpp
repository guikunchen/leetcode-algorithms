#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/sqrtx/


class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        // 计算结果与正确值 4634046340 相差 10^{-11}，这样在对结果取整数部分时，会得到 4633946339 这个错误的结果。
        // 因此在得到结果的整数部分 \textit{ans}ans 后，我们应当找出 ans 与 ans+1 中哪一个是真正的答案。
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};

class Solution {
public:
    int mySqrt(int x) {
        // x 平方根的整数部分 ans 是满足 k^2 ≤ x 的最大 k 值
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    // 牛顿迭代法，函数y = x² - C借助泰勒级数，从初始值x 开始快速向零点逼近。
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};