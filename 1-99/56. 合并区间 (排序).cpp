#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/merge-intervals/

class Solution {
public:
	// 先按区间左边排好序，然后再遍历一遍，合并就可以了
	// vecto最后一个元素是 back()，第一个是front()。
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	if(intervals.size() == 0){
    		return {};
    	}
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i = 0; i < intervals.size(); i++){
        	int left = intervals[i][0], right = intervals[i][1];
        	if(!merged.size() || merged.back()[1] < left){// 核心判断
        		merged.push_back({left, right});// 直接添加
        	}
        	else{
        		merged.back()[1] = max(merged.back()[1], right);// 合并区间右边
        	}
        }
        return merged;
    }
};