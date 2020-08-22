// https://leetcode-cn.com/problems/third-maximum-number/

// 也可以快排，得到下标
class Solution {// 维护三个最小的变量，而set自动排序
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        auto it = s.end();
        it--;
        if(s.size() >= 3) {
            it--;
            it--;
        }
        return *it;
    }
};