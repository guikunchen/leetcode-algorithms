#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/add-strings/

// 加完再反转
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        while(i >= 0 || j >= 0) {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            ans.push_back((sum % 10) + '0');
            i--, j--;
        }
        if(carry == 1) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};