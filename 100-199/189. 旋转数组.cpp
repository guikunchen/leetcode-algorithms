#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/rotate-array/solution/xuan-zhuan-shu-zu-by-leetcode/
/*给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4] */
// 1. 暴力，每次移1位，移动k次
// 2. 使用额外的数组
// 3. 环状替换
// 把元素看做同学，把下标看做座位，大家换座位。
// 第一个同学离开座位去第k+1个座位，第k+1个座位的同学被挤出去了，他就去坐他后k个座位，如此反复。
// 但是会出现一种情况，就是其中一个同学被挤开之后，坐到了第一个同学的位置（空位置，没人被挤出来），
// 但是此时还有人没有调换位置，这样就顺着让第二个同学换位置。 
// 那么什么时候就可以保证每个同学都换完了呢？n个同学，换n次，所以用一个count来计数即可。
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int count = 0;
        for (int start = 0; count < nums.size(); start++) {// 这里是count < nums.size()
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.length;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};
// 4. 反转三次
// 当我们旋转数组 k 次， k%n 个尾部元素会被移动到头部，剩下的元素会被向后移动。
class Solution {
public:
    // reverse 是左闭右开的函数
    void rotate(vector<int>& nums, int k) {
        int length = size(nums);
        k=k % length; 
        reverse(nums.begin(), nums.end());
        reverse(&nums[0], &nums[k]);
        // reverse(&nums[k], &nums[length]);
        reverse(&nums[k], nums.end());
    }
};