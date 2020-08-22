// https://leetcode-cn.com/problems/find-right-interval/
/*给定一组区间，对于每一个区间 i，检查是否存在一个区间 j，它的起始点大于或等于区间 i 的终点，这可以称为 j 在 i 的“右侧”。

对于任何区间，你需要存储的满足条件的区间 j 的最小索引，这意味着区间 j 有最小的起始点可以使其成为“右侧”区间。如果区间 j 不存在，则将区间 i 存储为 -1。最后，你需要输出一个值为存储的区间值的数组。*/
class Solution {
public:
    static bool cmp(vector<int>a,vector<int>b){
        return a[0] < b[0];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size(), -1);

        map<pair<int,int>,int> record;
        for(int i = 0; i < intervals.size(); i++) {
            record[make_pair(intervals[i][0],intervals[i][1])] = i;
        }

        sort(intervals.begin(), intervals.end(), cmp);// 按起点排序

        for(int i = 0; i < intervals.size(); i++) {
            int low = intervals[i][1];
            // 把下面的顺序查找弄成二分查找就变成nlogn
            for(int j = i + 1; j < intervals.size(); j++) {
                if(intervals[j][0] >= low) {
                    ans[record[make_pair(intervals[i][0],intervals[i][1])]] = record[make_pair(intervals[j][0],intervals[j][1])];
                    break;
                }
            }
        }
        return ans;
    }
};