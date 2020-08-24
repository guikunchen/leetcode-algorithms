#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/contains-duplicate-iii/

class Solution {
public:
    // 用自平衡二叉搜索树
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            auto bigger = s.lower_bound(nums[i]);
            // if(bigger != s.end() && *bigger - nums[i] <= t) return true;// 这样写会溢出，减负数
            if(bigger != s.end() && *bigger <= nums[i] + t) return true;
            auto smaller = s.upper_bound(nums[i]);
            // 左闭右开原则，所以要--smaller
            if(smaller != s.begin() && nums[i] <= *(--smaller) + t) return true;
            s.insert(nums[i]);
            if(s.size() > k){
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
    // 用桶排序
    // 映射规则，nums[i] / (t + 1)，这样同一个桶内最多相差t
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0) return false;
        long long mod = t + 1LL;// t+1可能会溢出，所以要 + 1LL
        unordered_map<long long, long long> buck;
        for(int i = 0; i < nums.size(); i++){
            long long index = nums[i] / mod;
            if(nums[i] < 0){
                index--;// 因为 -4 / 5 = 0，需要下移一位 
            }
            if(buck.find(index) != buck.end()) return true;
            else if(buck.find(index - 1) != buck.end()
                && abs(nums[i] - buck[index - 1]) <= t) return true;
            else if(buck.find(index + 1) != buck.end()
                && abs(nums[i] - buck[index + 1]) <= t) return true;
            buck[index] = nums[i];
            if(i >= k){// 维护滑动窗口
                buck.erase(nums[i - k] / mod);
            }
        }
        return false;
    }
};

