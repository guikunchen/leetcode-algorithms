#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/android-unlock-patterns

class Solution {
	vector<bool> visited;
public:
    int numberOfPatterns(int m, int n) {
    	int ans = 0;
    	for(int len = m; len <= n; ++len) {
    		visited = vector<bool> (9, false);
    		ans += backtrack(-1, len);
    	}
    	return ans;
    }

    bool isok(int idx, int last) {
    	if(visited[idx]) return false;// 已被访问过，不能到这里
    	if(last == -1) return true;//第一个数
    	if((idx+last)%2 == 1) return true;//相邻的两个数
    	int mid = (idx+last)/2;
    	if(mid == 4)//对角线的两个端点要连起来
    		return visited[mid];//看中点是否占用
    	if(idx%3 != last%3 && idx/3 != last/3)
    		return true;//不是 同行，或者 同列 的两个端点
    	return visited[mid];//检查0,6，中间是3，有没有被占用
    }

    int backtrack(int last, int len)
    {
    	if(len == 0) return 1;// 填的是最后一个
    	int sum = 0;
    	for(int i = 0; i < 9; ++i) {
    		if(isok(i, last)) {// 可以从last走到i
    			visited[i] = true;
    			sum += backtrack(i, len-1);
    			visited[i] = false;
    		}
    	}
    	return sum;
    }
};