#include<iostream>
#include<vector>
#include<set>
using namespace std;
// 答案只可能出现在[1,N+1]
// 先遍历一遍，把所有小于等于0的数换为N+1（或任意大于等于N+1的数）
// 然后再遍历一遍，比如num[20] == 100，那就把num[100 - 1]改成负数
// 最后遍历找到第一个大于0的，返回索引 + 1
class Solution {

// https://leetcode-cn.com/problems/first-missing-positive/

public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num: nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

/*
在恢复后，数组应当有 [1, 2, ..., N] 的形式，但其中有若干个位置上的数是错误的，每一个错误的位置就代表了一个缺失的正数。
以题目中的示例二 [3, 4, -1, 1] 为例，恢复后的数组应当为 [1, -1, 3, 4]，我们就可以知道缺失的数为 22。

那么我们如何将数组进行恢复呢？我们可以对数组进行一次遍历，对于遍历到的数，把他放到该放的位置。

注意到上面的方法可能会陷入死循环。如果恰好相等，那么就会无限交换下去。

*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {}

                return i + 1;
            }
        }
        return n + 1;
    }
};
