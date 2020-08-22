// https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/

class Solution {// nlogn
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());// 先排序，每一步利用最大值和最小值的差值移动
        // 第一步移动num[n - 1] - num[0]步，然后num[n - 2]最大，移动num[n - 2] - num[0]步
        int moves;
        for(int i = nums.size() - 1; i > 0; i--) {
            moves += nums[i] - nums[0];
        }
        return moves;
    }
};

class Solution {// 动态规划nlogn
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());// 先排序，移动到i时，假设i-1及之前的数都更新为nums[i-1]
        int moves = 0;
        for(int i =  1; i < nums.size(); i++) {
            nums[i] += moves;// 以前move过的距离
            int diff = nums[i] - nums[i - 1];
            moves += diff;// 从i - 1变到i，保持i不动，其他n-1个元素都加了diff，所以用moves记录
        }
        return moves;
    }
};

class Solution {// 数学分析
public:// 将除了一个元素之外的全部元素+1，等价于将该元素-1，因为我们只对元素的相对大小感兴趣。
// 因此，该问题简化为需要进行的减法次数。显然，我们只需要将所有的数都减到最小的数即可。
    int minMoves(vector<int>& nums) {
        int minVal = INT_MAX;
        for(int num : nums) {
            minVal = min(minVal, num);
        }
        int moves = 0;
        for(int num : nums) {
            moves += num - minVal;
        }
        return moves;
    }
};