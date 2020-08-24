#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/word-search/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();

        int cur = nums[0];
        int count = 1;
        int overflow = 0;
        for (int curIndex = 1; curIndex < nums.size(); curIndex++) {
            nums[curIndex - overflow] = nums[curIndex];
            if(nums[curIndex] != cur) {
                cur = nums[curIndex];
                count = 1;
                continue;
            } else {
                count++;
                if(count > 2) {
                    overflow++;
                }
            }
        }
        return nums.size() - overflow;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
        {
            return n;
        }
        int sp = 1;
        // 若相等，往右移动快指针
        // 若不等，慢指针右移，然后把快指针所指向的元素写入慢指针所在位置
        for(int fp = 2; fp < n; fp++)
        {
            if(nums[fp] != nums[sp - 1])
            {
                nums[++sp] = nums[fp];
            }
        }
        return sp + 1;
    }
};