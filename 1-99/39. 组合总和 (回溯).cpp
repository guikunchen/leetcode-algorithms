#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/combination-sum/
/*给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。  */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> solution;
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
            backtracking(candidates, target - candidates[i], i, solution, result);
            solution.pop_back();
        }
    }
};