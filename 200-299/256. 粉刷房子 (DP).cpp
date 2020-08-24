#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/paint-house
/*假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其与相邻的两个房子颜色不能相同。
当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x 3 的矩阵来表示的。
例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。请你计算出粉刷完所有房子最少的花费成本。
*/
class Solution {
public:// dp[i][c] 表示刷完 i 房子后，i 房子是 c 颜色时，花费最小多少
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), house, color;
        if(n==0) return 0;
        vector<vector<int>> dp(n,vector<int>(3));
        dp[0] = costs[0];// 第一个刚好相等
        // 只依赖于上一个状态，其实可以优化空间复杂度为O 1
        for(house = 1; house < n; house++) {
            for(color = 0; color < 3; ++color) {
                dp[house][color] = costs[house][color] + min(dp[house-1][(color+1)%3], dp[house-1][(color+2)%3]);
            }
        }
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};