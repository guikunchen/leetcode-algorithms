#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return ;
        rows = matrix.size();
        cols = matrix[0].size();
        dp = vector<vector<int>>(rows+1, vector<int>(cols + 1, 0));
        for (int i = 1; i < rows + 1; i++){
            for (int j = 1; j < cols + 1; j++){
                dp[i][j] = dp[i][j-1] + dp [i-1][j] - dp[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }

private:
    int rows,cols; 
    vector<vector<int>>dp;
};