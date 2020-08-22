#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/line-reflection
/*在一个二维平面空间中，给你 n 个点的坐标。
问，是否能找出一条平行于 y 轴的直线，让这些点关于这条直线成镜像排布？

示例 1：
输入: [[1,1],[-1,1]]
输出: true

示例 2：
输入: [[1,1],[-1,-1]]
输出: false
拓展：
你能找到比 O(n^2) 更优的解法吗?*/

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),[&](auto a, auto b){
        	if(a[0] == b[0])
        		return a[1] < b[1];//y大的靠后
        	return a[0] < b[0];//按x坐标排序
        });
        if(points[0][0] == points[points.size() - 1][0])//x都相等，在一条线上，true
        	return true;
        points.erase(unique(points.begin(), points.end()), points.end());//去重

        int half = points.size()/2;
        sort(points.begin(), points.begin()+half, [&](auto a, auto b){
        	if(a[0] == b[0])
        		return a[1] > b[1];//前半部分y大的靠前
        	return a[0] < b[0];//按x坐标排序
        });

        int l = 0, r = points.size()-1;// 排序后，l指向最左边最高的，r指向最右边最高的
        if(points[l][1] != points[r][1]) return false;// 高度不等
        int xmid = points[l++][0] + points[r--][0];//中心的两倍
        while(l < r) {
        	if(points[l][0] != points[r][0] // 同一条直线上两个点就是镜像点
        		&& (points[l][1] != points[r][1] || points[l][0] + points[r][0] != xmid)) {// 高度或横坐标和不等
        		return false;
        	} 
            l++,r--;
        }
    	return points[l][0] + points[r][0] == xmid;
    }
};