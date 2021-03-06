#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/moving-average-from-data-stream
/*给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算其所有整数的移动平均值。

示例:
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3*/

class MovingAverage {
	queue<int> q;
	int sum = 0;
    int cap;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
    	cap = size;
    }
    
    double next(int val) {
    	sum += val;
        q.push(val);
    	if(q.size() > cap) {// 更新滑动窗口
    		sum -= q.front();
    		q.pop();
    	}
    	return sum/double(q.size());
    }
};