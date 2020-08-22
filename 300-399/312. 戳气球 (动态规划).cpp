#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/burst-balloons/
class Solution {// 把戳气球等价为在中间添加气球的问题
public:
    vector<vector<int>> rec;// rec[left][right]表示在(left,right)中间填满气球
    vector<int> val;// 在nums前后加1，防止溢出
public:
    int solve(int left, int right) {
        if (left >= right - 1) {
            return 0;
        }
        if (rec[left][right] != -1) {// 初始值都记为-1，记忆化递归
            return rec[left][right];
        }
        for (int i = left + 1; i < right; i++) {
            int sum = val[left] * val[i] * val[right];
            sum += solve(left, i) + solve(i, right);
            rec[left][right] = max(rec[left][right], sum);
        }
        return rec[left][right];
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n + 2);
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        val[0] = val[n + 1] = 1;
        rec.resize(n + 2, vector<int>(n + 2, -1));
        return solve(0, n + 1);
    }
};

class Solution {// 递归可以转动态规划
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> rec(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {// 要注意顺序，从小计算到大
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {// 在(i,j)里插入气球
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = max(rec[i][j], sum);
                }
            }
        }
        return rec[0][n + 1];
    }
};