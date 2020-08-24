#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n > 0) {
            n -= 1;// 需要把1-26映射到0-25
            ans.push_back('A' + (n % 26));
            n /= 26;
        }
        reverse(ans.begin(), ans.end());// 每次计算最低位，所以最后要逆序
        return ans;
    }
};