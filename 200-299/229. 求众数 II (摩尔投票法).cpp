#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/majority-element-ii/ 第一题169

// 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

// 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

// 示例 1:

// 输入: [3,2,3]
// 输出: [3]
// 摩尔投票法

class Solution {
public:
    // 要求数量大于 n/k，则最多有k-1个众数
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0) return ans;
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        for(auto num : nums) {// 投票，互相抵消
            if(num == candidate1) {
                count1++;
            } else if(num == candidate2) {
                count2++;
            } else if(count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if(count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(auto num : nums) {
            if(num == candidate1) {
                count1++;
            } else if(num == candidate2) {
                count2++;
            }
        }
        // 要判断candidate的数量到底有没有达到要求，同时要看不同变量是否存储相同的candidate
        int n = nums.size();
        if(count1 > n / 3) {
            ans.push_back(candidate1);
        }
        if(count2 > n / 3) {
            ans.push_back(candidate2);
        }
        return ans;
    }
};