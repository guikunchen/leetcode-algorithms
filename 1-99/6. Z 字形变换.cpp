#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        
        vector<string> rows(min(int(s.length()), numRows));
        bool goingdown = false;
        int index = 0;
        
        for(char c : s){
            rows[index] += c;
            if(index==0 || index==numRows-1) goingdown = !goingdown;
            index += (goingdown ? 1 : -1);
        }
        
        string ans;
        for(string row : rows) ans += row;
        return ans;
    }
};

// vector数组的初始化

// 遍历for循环

// 三元表达式用于控制方向

// string可以 +='a' 也可以 +="ab"