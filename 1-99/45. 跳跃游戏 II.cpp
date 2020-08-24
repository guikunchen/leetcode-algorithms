#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/jump-game-ii/ 第一题55
/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int new_max = 0, maxi = 0, steps = 0, size = nums.size();
        // maxi记录当前步的最远索引
        // new_max记录下一步的最远索引
        // 走到maxi的时候step+1，然后maxi更新为new_max，检查一下是否能到达终点
        for(int i = 0; i < size - 1; i++) {
        	int num = nums[i];
        	new_max = max(new_max, i + num);
        	if(i == maxi) {
        		steps++;
        		maxi = new_max;
        		if(new_max >= size - 1) {
        			break;
        		}
        	}
        }
        return steps;
    }
};