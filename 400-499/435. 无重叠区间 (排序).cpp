// https://leetcode-cn.com/problems/non-overlapping-intervals/
// 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
class Solution {
public:
    static bool cmp(vector<int>a,vector<int>b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        //按照区间终结点，从小到大排序
        sort(intervals.begin(), intervals.end(),cmp);
        
        //获取最小的，区间终结点
        int end = intervals[0][1];
        int res = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            //如果区间的起点，小于上一个区间的终点，说明有交集，要删除
            if (intervals[i][0] < end) {
                ++res;
            } else {
                //没有交集，更新end
                end = intervals[i][1];
            }
        }
        return res;
    }
};