#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/combinations/

class Solution {
public:
    vector<vector<int>>res;

    vector<vector<int>> combine(int n, int k) {
        if (k <= 0 || n <= 0) return res;
        vector<int> track;
        backtrack(n, k, 1, track);
        return res;
    }

    void backtrack(int n, int k, int start, vector<int>& track) {
        // 到达树的底部
        if (k == track.size()) {
            res.push_back(track);
            return;
        }
        // 注意 i 从 start 开始递增
        for (int i = start; i <= n; i++) {
            // 做选择
            track.push_back(i);
            backtrack(n, k, i + 1, track);
            // 撤销选择
            track.pop_back();
        }
    }
};

class Solution {
public:
    // 也可以用二进制的思想解决
    vector<vector<int>> combine(int n, int k) {
        vector<int> map(n, 0);
        vector<vector<int>> res;
        for(int i = 0; i < k; i++)
            map[i] = 1;
        vector<int> tmp;
        do {
            for(int i = 0; i < n; i++)
                if(map[i])  tmp.push_back(i+1);
            res.push_back(tmp);
            tmp.clear();
        } while(prev_permutation(map.begin(),map.end()));
        // prev_permutation 生成降序排列
        return res;
    }
};