#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/climbing-stairs/
/*假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶 */

class Solution {
public:
    // 有点像斐波那契数列
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
    // 优化一下，用两个变量存储
    int climbStairs(int n) {
        if(n <= 2) return n;
        int first = 1;
        int second = 2;
        for(int i = 2; i < n; i++) {
            second = second + first;
            first = second - first;
        }
        return second;
    }
    // 再优化，直接数学公式求解
    int climbStairs(int n) {
        double sqrt5 = Math.sqrt(5);
        double fibn = Math.pow((1 + sqrt5) / 2, n + 1) - Math.pow((1 - sqrt5) / 2, n + 1);
        return (int)(fibn / sqrt5);// pow用掉logn时间
    }
    // 用矩阵快速幂的方式求解，也是logn时间
};