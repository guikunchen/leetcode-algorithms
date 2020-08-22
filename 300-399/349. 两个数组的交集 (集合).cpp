#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/intersection-of-two-arrays/

class Solution {
public:
	// 最简单的
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> s, res;
        for(int v : nums1) s.insert(v);
        for(int v : nums2)
            if(s.find(v) != s.end())
                res.insert(v);
        for(int e : res) ans.push_back(e);
        return ans;
    }

    // 稍做优化
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> s;
        for(int v : nums1) s.insert(v);
        for(int v : nums2)
            if(s.find(v) != s.end()){// 边遍历边删除集合中的元素
                ans.insert(v);
                s.erase(v);
            }
        return ans;
    }
};

// 用空间换时间