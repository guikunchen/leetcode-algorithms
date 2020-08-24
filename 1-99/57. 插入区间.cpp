#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/insert-interval/

class Solution {
public:
    // 直接模拟插入过程
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> ans;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {// 比较小的区间一直放进去
            ans.push_back(intervals[i++]);
        }
        ans.push_back(newInterval);// 把插入区间放进去
        while (i < intervals.size()) {
            vector<int> &itvl1 = ans[ans.size()-1], &itvl2 = intervals[i++];
            if (itvl2[0] <= itvl1[1]) {// 合并区间
                itvl1[0] = min(itvl1[0], itvl2[0]);
                itvl1[1] = max(itvl1[1], itvl2[1]);
            } else {
                ans.push_back(itvl2);
            }
        }
        return ans;
    }
};