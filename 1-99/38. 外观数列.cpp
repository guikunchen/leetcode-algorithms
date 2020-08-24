#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/valid-sudoku/

class Solution {
public:
	string calculate(string &input) {
		int i = 0;
		string ans;
		while(i < input.size()) {
			int count = 1;
			char num = input[i];
			while(i + count < input.size() && input[i + count] == num) {
				count++;
			}
			ans.append(1, count + '0');
			ans.append(1, num);
			i += count;
		}
		return ans;
	}
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; i++) {
        	ans = calculate(ans);
        }
        return ans;
    }
};