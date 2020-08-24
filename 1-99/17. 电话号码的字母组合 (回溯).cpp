#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
	vector<string> sList={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; //字符表
	vector<string> ans;
	string cur;

	void backtracking(int index, string & digits) {
		int num = digits[index] - '0';
		if(index == digits.size()) {
			ans.push_back(cur);
			return;
		}

		for(int i = 0; i < sList[num].size(); i++) {
			cur.push_back(sList[num][i]);
			backtracking(index + 1, digits);
			cur.pop_back();
		}
	}
    vector<string> letterCombinations(string digits) {
    	if(digits.size() == 0) return ans;

    	backtracking(0, digits);
    	return ans;
    }
};