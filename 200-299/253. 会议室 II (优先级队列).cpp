#include<iostream>
#include<vector>
#include<set>
using namespace std;

// 给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],…] (si < ei)，
// 为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。

// 输入: [[0, 30],[5, 10],[15, 20]]
// 输出: 2
class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals.size();

        sort(intervals.begin(), intervals.end(), cmp);

        priority_queue<int, vector<int>, greater<int> > pq;// 最小堆,存放会议室结束时间，小的在上
        int ans = 1;

    	for(int i = 0; i < intervals.size(); i++) {
            while(!pq.empty() && intervals[i][0] >= pq.top()) {// 最早结束的会议室可用，占用它
                pq.pop();
            }
            pq.push(intervals[i][1]);
            ans = max(ans, pq.size());
        }

        return ans;
    }
};