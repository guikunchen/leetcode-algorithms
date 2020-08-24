#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/missing-ranges
// 给定一个排序的整数数组 nums ，其中元素的范围在 闭区间 [lower, upper] 当中，
// 返回不包含在数组中的缺失区间。
// 输入: nums = [0, 1, 3, 50, 75], lower = 0 和 upper = 99,
// 输出: ["2", "4->49", "51->74", "76->99"]
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        long l = lower;
        vector<string> ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(l == nums[i])
                l++;//相等，我跳过你
            else if(l < nums[i])
            {   //有空缺
                if(l < nums[i]-1)//大于1
                    ans.push_back(to_string(l)+"->"+to_string(nums[i]-1));
                else if(l == nums[i]-1)//等于1
                    ans.push_back(to_string(l));
                l = long(nums[i])+1;//更新l到nums[i]下一个数
                // [2147483647]
                // 0
                // 2147483647
            }
        }
        // 处理最后一段
        if(l < upper)
            ans.push_back(to_string(l)+"->"+to_string(upper));
        else if(l==upper)
            ans.push_back(to_string(l));
        return ans;
    }
};