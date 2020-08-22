// https://leetcode-cn.com/problems/super-pow/
// 你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int size = b.size();
        int x = a % 1337;
        int res = 1;
        for (int i=size-1; i>=0; i--) {
            int pow = b[i];
            res = (res * qpow(x, pow))%1337;// (a * b) % c = (a%c)(b%c) % c 简单来说模就完事了
            x = qpow(x, 10)%1337;// x ^ 33 = x ^ 3 + (x^10) ^3
        }
        return res;
    }
    
    int qpow(int x, int n) {// 快速幂
        int res = 1;
        while (n) {
        if (n & 1) {
            res = (res * x) % 1337;
        }
            x = (x * x)  % 1337;
            n >>= 1;
        }
        return res;
    }
};