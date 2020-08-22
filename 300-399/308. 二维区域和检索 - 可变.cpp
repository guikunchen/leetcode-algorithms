#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/range-sum-query-2d-mutable/
// 给你一个 2D 矩阵 matrix，请计算出从左上角 (row1, col1) 到右下角 (row2, col2) 组成的矩形中所有元素的和。

// 二维树状数组可以更高效，树状数组默写不来，用行的前缀和做，时间复杂度O(n)
// 二维树状数组时间可以 logn
class NumMatrix {
    vector<vector<int>> mat;
    vector<vector<int>> rowpresum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        rowpresum = matrix;
        for(int i = 0, j; i < matrix.size(); ++i)
        {
            for(j = 1; j < matrix[0].size(); ++j)
                rowpresum[i][j] = rowpresum[i][j-1] + matrix[i][j];
        }
    }
    
    void update(int row, int col, int val) {
        mat[row][col] = val;
        rowpresum[row][col] = (col > 0 ? rowpresum[row][col-1] : 0) + val;
        for(int j = col+1; j < mat[0].size(); ++j)
            rowpresum[row][j] = rowpresum[row][j-1] + mat[row][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; ++i)
        {
            sum += rowpresum[i][col2] - (col1==0 ? 0 : rowpresum[i][col1-1]);
        }
        return sum;
    }
};