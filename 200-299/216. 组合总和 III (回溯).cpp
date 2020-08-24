#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/combination-sum-iii/ 39题 377题
/*找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]] */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int >cur;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k,n,1);
        return ans;
    }
    void dfs(int k,int sum,int r)//k记录次数，sum记录和，r用来确保数列里的数是递增的，确保不会有重复。
    {
        if(k==0&&sum==0)
        {
            ans.push_back(cur);
            return;
        }
        if(k==0||sum<0)// 不能再放数字了，或者和超过了给定n
            return;
        for(int i=r;i<=9;i++)// 只能放 1 - 9 {
            cur.push_back(i);
            dfs(k-1,sum-i,i+1);
            cur.pop_back();
        }
        return;
    }
};