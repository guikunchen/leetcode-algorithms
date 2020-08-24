#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/paint-house-ii/
/*假如有一排房子，共 n 个，每个房子可以被粉刷成 k 种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。
当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。
每个房子粉刷成不同颜色的花费是以一个 n x k 的矩阵来表示的。
*/
class Solution {
public:// 时间 O nk  空间 O 1
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size()==0 || costs[0].size()==0)
            return 0;
        int m = costs.size()// m 是房子总数
        int n = costs[0].size();// n 是颜色总数
        int prevColor = -1;// 前一个花费最小的颜色
        int prevMin1 = 0;// 前一个花费最小的
        int prevMin2 = 0;// 前一个花费第二小的
        for(int i = 0; i < m; ++i)
        {
            int curMin1 = INT_MAX, curMin2 = INT_MAX;// 这一轮花费最小的两个值
            int minColor;// 花费最小的那个值对应的颜色
            for(int curColor = 0; curColor < n; ++curColor) {
                //跟前一个最小花费颜色一样，加上第二小的。不一样，加上最小的
                int cost = (curColor==prevColor ? costs[i][curColor]+prevMin2 : costs[i][curColor]+prevMin1);
                if(cost <= curMin1) {
                    curMin2 = curMin1;
                    curMin1 = cost;
                    minColor = curColor;
                } else if(cost < curMin2) {
                    curMin2 = cost;
                }
            }
            prevMin1 = curMin1;
            prevMin2 = curMin2;
            prevColor = minColor;
        }
        return prevMin1;
    }
};