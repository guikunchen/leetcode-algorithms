// https://leetcode-cn.com/problems/contains-duplicate-ii/

class Solution {
public:
    // 很朴实的操作
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> hm;
        for(int i = 0; i < nums.size(); i++){
            hm[nums[i]].push_back(i);// 存起来
        }
        for(pair<int, vector<int>> p : hm){// 再遍历
            vector<int> tmp = p.second;
            for(int i = 0; i < tmp.size() - 1; i++){// 至少要出现两次
                if(abs(tmp[i] - tmp[i + 1]) <= k) return true;
            }
        }
        return false;
    }

    // 稍微优化一下，存起来之前就判断，而且value只要记录最后一次出现的位置即可
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        for(int i = 0; i < nums.size(); i++){
            if(hm.find(nums[i]) != hm.end()){// 出现过
                if(abs(i - hm[nums[i]]) <= k) return true;
            }
            hm[nums[i]] = i;// 存起来
        }
        return false;
    }

    // 滑动窗口，应该是最好的解法，用set维护一个大小为k的滑动窗口
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) != s.end()) return true;// 存在元素
            s.insert(nums[i]);
            if(s.size() > k){
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};