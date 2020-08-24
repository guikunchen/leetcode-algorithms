#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

// https://leetcode-cn.com/problems/max-points-on-a-line/

/*
时间复杂度：O(N^2)(双重循环)
因为通过点 0 最多有 N-1 条直线，通过点 1 最多有 N-2 条直线，
所以结果共有 (N - 1) + (N - 2) + .. + 1 = N(N - 1)/2 次操作，
因此时间复杂度为 O(N^2)。
空间复杂度： O(N)，用来记录最多不超过 N-1 条直线。（map循环内更新）
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.empty() || points.size() == 0){
            return 0;
        }
        if(points.size()<3){
            return points.size();
        }
        int res = 0;
        int n = points.size();
        for(int i = 0; i<n; i++){
            int p1_x = points[i][0];
            int p1_y = points[i][1];
            int max_points = 0;// 各个斜率中最多的点
            int same_points = 1;// 该点的重复点
            //unorderedmap默认只能用基本类型，string和智能指针作为key，除非你提供hash函数，就是上面模板第二个参数
            map<pair<int, int>, int> count;
            for(int j = i+1; j<n; j++){
                int p2_x = points[j][0];
                int p2_y = points[j][1];
                if(p1_x == p2_x && p1_y == p2_y){
                    ++same_points;
                }else{
                    max_points = max(max_points, ++count[getSlope(p1_x, p1_y, p2_x, p2_y)]);
                }
            }
            res = max(res, max_points + same_points);
        }
        return res;
    }
private:
    //gcd(dy,dx), (4,2) = (2,1), (6,3) = (2,1)
    pair<int, int> getSlope(int p1_x, int p1_y, int p2_x, int p2_y){
        int dx = p2_x - p1_x;
        int dy = p2_y - p1_y;
        if(dx == 0){
            return {0, p1_x};
        }
        if(dy == 0){
            return {p1_y, 0};
        }
        int d = gcd(dy, dx);
        return {dy/d, dx/d};
    }
    //gcd(m, n) = gcd(n, m%n)
    //GCD算法是用于求解最大公约数的方法，利用了欧几里得算法，即辗转相除法
    //https://blog.csdn.net/wzx15927662183/article/details/90212839
    int gcd(int m, int n){
        return n == 0 ? m : gcd(n, m%n);
    }
};