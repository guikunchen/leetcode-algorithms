#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/single-number-iii/  136题
/*给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

示例 :

输入: [1,2,1,3,2,5]
输出: [3,5]*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // difference between two numbers (x and y) which were seen only once
        int bitMask = 0;
        for(auto num : nums) {
            bitMask ^= num;
        }
        // rightmost 1-bit diff between x and y
        int diff = bitMask & (-bitMask);// n & (-n) 得到最右边的1 

        int x = 0;// bitmask which will contain only x
        for(int num : nums){
            if(num & diff){
                x ^= num;
            }
        }
        return {x, x ^ bitMask};// 右边可以把bitMask中的x消掉只剩下y
    }
};