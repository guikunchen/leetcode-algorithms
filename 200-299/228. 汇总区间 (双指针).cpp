#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/summary-ranges
/*给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

示例 1:

输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。 */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;

        int i = 0;// i是区间起点，j是区间终点
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[j + 1] == nums[j] + 1) j++;

            if (i == j) ans.push_back(to_string(nums[i]));
            else 
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
                
            i = j + 1;
        }
        return ans;
    }
};