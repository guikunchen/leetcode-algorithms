// https://leetcode-cn.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int n : nums){
            if(s.find(n) != s.end()) return true;
            s.insert(n);
        }
        return false;
    }

    // 上面是一种方法，效率还行 O n
    // 也可以先堆排序，再线性遍历一次，O nlogn ，空间是1或者n，取决于有没有使用副本
};