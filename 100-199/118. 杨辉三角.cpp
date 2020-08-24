#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/pascals-triangle/
// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++)
            res.push_back(vector<int>(i+1,1));

        for(int i=0;i<numRows;i++)
            for (int j = 1; j < i; j++)
             res[i][j]=res[i-1][j-1]+res[i-1][j];
        return res;
    }
};