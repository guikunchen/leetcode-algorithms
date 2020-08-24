#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/search-a-2d-matrix-ii/ 第一题74

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=matrix.size()-1,j=0;// 从右上角开始，也可以从左下角开始
        while(i>=0&&j<matrix[0].size())
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) i--;
            else j++;
        return false;
    }
};