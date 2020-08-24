#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/wiggle-sort
/*给你一个无序的数组 nums, 将该数字 原地 重排后使得 nums[0] <= nums[1] >= nums[2] <= nums[3]...。
输入: nums = [3,5,2,1,6,4]
输出: 一个可能的解答是 [3,5,1,6,2,4]
*/
class Solution {
public:
    // 考虑连续的三个数abc，如果中间最大，那原本a<b，如果b<c，交换以后同样满足中间最大
    // 考虑连续的三个数abc，如果中间最小，那原本a>b，如果b>c，交换以后同样满足中间最小
    void wiggleSort(vector<int>& nums) {
    	for(int i = 0; i < nums.size() - 1; i++) {
            if((i & 1 == 1) && nums[i] < nums[i + 1]) {// 奇数索引。两侧应小于他
                swap(nums[i], nums[i + 1]);
            } else if((i & 1 == 0) && nums[i] > nums[i + 1]){// 偶数索引。两侧应大于他
                swap(nums[i], nums[i + 1]);
            }
        }
    }
};