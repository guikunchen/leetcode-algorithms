#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/majority-element/ 第二题229

class Solution {
public:
    //解法1：哈希表
    int majorityElement_1(vector<int>& nums) {
        unordered_map<int,int> record;//元素->频率
        int half = nums.size() >> 1;
        for(int i=0;i<nums.size();++i)
        {
            record[nums[i]]++;
            if(record[nums[i]] > half) return nums[i];
        }
        return -1;
    }
    
    //解法2：排序
    //由于众数出现的频率大于n/2,所以在排序之后众数必存在于下标[n/2]处(本题默认数组中是一定存在众数的，所以返回下标[n/2]可行)
    int majorityElement_2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int half = nums.size() >> 1;
        return nums[half];
    }
    
    //解法3：摩尔投票法
    //摩尔投票法，遇到相同的数，就投一票，遇到不同的数，就减一票，最后还存在票的数就是众数
    int majorityElement(vector<int>& nums)
    {
        int count=0,result=-1;
        for(const auto& num:nums)
        {
            if(count==0)result=num;
            if(num==result)++count;
            else --count;
        }
        return result;
    }
};