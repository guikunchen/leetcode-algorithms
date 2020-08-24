#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/generate-parentheses/

class Solution {// 官方题解
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {// 右括号能否放置的关键
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};

class Solution {// 自己写的，也可以通过
public:
	vector<string> ans;
	string cur;
	int left, right;

	void backtracking(int index, int n) {
		if(index == n << 1) {
			ans.push_back(cur);
			return;
		}

		if(left > 0) {
			cur.push_back('(');
			left--;
			backtracking(index + 1, n);
			left++;
			cur.pop_back();
		}
		if(right > left) {// 关键
			cur.push_back(')');
			right--;
			backtracking(index + 1, n);
			right++;
			cur.pop_back();
		}
	}

    vector<string> generateParenthesis(int n) {
    	if(n <= 0) return ans;

    	left = right = n;
    	backtracking(0, n);
    	return ans;    
    }
};