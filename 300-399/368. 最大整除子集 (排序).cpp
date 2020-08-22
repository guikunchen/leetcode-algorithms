#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/line-reflection
/*给出一个由无重复的正整数组成的集合，找出其中最大的整除子集，子集中任意一对 (Si，Sj) 都要满足：Si % Sj = 0 或 Sj % Si = 0。

如果有多个目标子集，返回其中任何一个均可。

示例 1:
输入: [1,2,3]
输出: [1,2] (当然, [1,3] 也正确)

示例 2:
输入: [1,2,4,8]
输出: [1,2,4,8]*/

/*先排序，从后往前找能够整除的
记录最大长度，同时记录最长的序列 前一个可以整除的 idx
时间复杂度O(n2)，空间复杂度O(n)*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()) return {};
        sort(nums.begin(), nums.end());
        int i, j, n = nums.size();
        int maxlen = 1, maxlenid = 0;
        vector<pair<int,int>> dp(n);//到该位置的最大长度，前一个idx
        for(i = 0; i < n; ++i)
            dp[i] = make_pair(1, -1);

        for(i = 1; i < n; ++i) {
            for(j = i-1; j >= 0; --j) {
                if(nums[i]%nums[j] == 0 && dp[j].first+1 > dp[i].first) {
                    dp[i].first = dp[j].first + 1;//最大长度
                    dp[i].second = j;//前一个数的idx
                }
            }
            if(dp[i].first > maxlen) {
                maxlen = dp[i].first;//最大长度
                maxlenid = i;//最大长度的结束数字
            }
        }

        vector<int> ans(maxlen);
        ans[maxlen-1] = nums[maxlenid];//最后一个数字
        for(i = maxlen-2; i >= 0; --i) {
            ans[i] = nums[dp[maxlenid].second];//前一个数字
            maxlenid = dp[maxlenid].second;//向前递推
        }
        return ans;
    }
};