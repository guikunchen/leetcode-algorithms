// https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
// 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while(m < n) {
            m >>= 1;
            n >>= 1;
            shift++;
        }
        return m << shift;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(m < n) {
            n = n & (n - 1);// 消掉最右边的1
        }
        return m & n;
    }
};