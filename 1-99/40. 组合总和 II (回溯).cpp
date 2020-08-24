#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/combination-sum-ii/
/*给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中 只能使用一次 。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。  */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> solution;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, solution, result);
        return result;
    }
    void backtracking(vector<int>& candidates, int target, int start, vector<int>& solution, vector<vector<int>>& result) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            result.push_back(solution);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            solution.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i + 1, solution, result);
            solution.pop_back();
            while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            	i++;
            }
        }
    }
};