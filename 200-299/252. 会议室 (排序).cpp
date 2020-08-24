#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/meeting-rooms
/*给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)
，请你判断一个人是否能够参加这里面的全部会议。
*/
class Solution {    //C++
public:// 按开始时间排序后，依次检查相邻前一个的结束和后一个的开始时间是否重叠
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[&](auto a, auto b){
            return a[0] < b[0];
        });
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i-1][1] > intervals[i][0])
                return false;
        }
        return true;
    }
};