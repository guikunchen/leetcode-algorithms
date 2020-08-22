#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/patching-array/

/*  初始化区间 [1, miss) = [1, 1) = 空
    每当 n 没有被覆盖
        若当前元素 nums[i] 小于等于 miss
            将范围扩展到 [1, miss + nums[i])
            将 i 增加 1
        否则
            将 miss 添加到数组，将范围扩展到 [1, miss + miss)
            增加数字的计数
    返回增加数字的数目*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0, i = 0;
        long miss = 1; // use long to avoid integer overflow error
        // 覆盖区间[1, miss)
        while (miss <= n) {
            if (i < nums.length && nums[i] <= miss) // miss is covered
                miss += nums[i++];
            else { // patch miss to the array
                miss += miss;
                patches++; // increase the answer
            }
        }
        return patches;
    }
};