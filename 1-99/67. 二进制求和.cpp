#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};


// a & b 的结果，左移一位（<< 1）就得到进位数
// a ^ b ，异或，其实就是不带进位的加法，结果更新给 a
const addBinary = (a, b) => {
  a = parseInt(a, 2);
  b = parseInt(b, 2);
  while (b != 0) {
    let carry = a & b;
    a = a ^ b;
    b = carry << 1;
  }
  return a.toString(2);
};