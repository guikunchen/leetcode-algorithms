#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/multiply-strings/

// 竖式每位乘完的位置是固定的
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        vector<int> mem(num1.size() + num2.size(), 0);
        for(int i = num1.size() - 1; i >= 0; i--) {
        	int n1 = num1[i] - '0';
        	for(int j = num2.size() - 1; j >= 0; j--) {
        		int n2 = num2[j] - '0';
        		int sum = mem[i + j + 1] + n1 * n2;
        		mem[i + j] += sum / 10;// 处理进位
        		mem[i + j + 1] = sum % 10;
        	}
        }

        string res;
        for(int i = 0; i < mem.size(); i++) {
        	if(i == 0 && mem[i] == 0) continue;
        	res.push_back(mem[i] + '0');
        }
        return res;
    }
};