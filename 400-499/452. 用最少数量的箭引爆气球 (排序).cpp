#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() <= 1) return points.size();

        // sort(points.begin(), points.end(), cmp);
        sort(begin(points), end(points),
            [](const vector<int> &o1, const vector<int> &o2) {
                return (o1[1] < o2[1]);
            });

        int index = 0, arrows = 0;
        while(index < points.size()) {
            int endIndex = points[index][1];
            index++;
            arrows++;
            while(index < points.size() && points[index][0] <= endIndex) {// 这里必须要小于等于
                index++;
            }
        }

        return arrows;
    }
};