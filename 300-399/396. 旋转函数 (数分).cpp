// https://leetcode-cn.com/problemsum/rotate-function/

class Solution {
public:// 写三个式子寻找规律
    int maxRotateFunction(vector<int>& A) {
        long N = A.size();
        long sum = 0;
        long cur = 0;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            cur += i * A[i];
        }
        long res = cur;
        for (int i = N - 1; i >= 0; --i) {
            // F(k+1) = F(k) + sum - n * Bk[n-1]
            cur = cur + sum - N * (long)A[i];
            res = max(res, cur);
        }
        return res;
    }
};