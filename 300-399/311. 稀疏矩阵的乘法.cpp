#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/sparse-matrix-multiplication
// 给你一个 2D 矩阵 matrix，请计算出从左上角 (row1, col1) 到右下角 (row2, col2) 组成的矩形中所有元素的和。

// 给你两个 稀疏矩阵 A 和 B，请你返回 AB 的结果。你可以默认 A 的列数等于 B 的行数。
class Solution {// 选取都不为0的行和列相乘
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<bool> r_all0(A.size(),true);
        vector<bool> c_all0(B[0].size(),true);
        int i, j, k, sum;
        bool flag = false;
        for(i = 0; i < A.size(); ++i)
        {
            flag = false;
            for(j = 0; j < A[0].size(); ++j)
            {
                if(A[i][j])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                r_all0[i] = false;
        }
        for(j = 0; j < B[0].size(); ++j)
        {
            flag = false;
            for(i = 0; i < B.size(); ++i)
            {
                if(B[i][j])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                c_all0[j] = false;
        }
        vector<vector<int>> ans(A.size(), vector<int>(B[0].size(), 0));
        for(i = 0; i < A.size(); ++i)
            for(j = 0; j < B[0].size(); ++j)
            {
                if(r_all0[i] || c_all0[j])
                    continue;
                sum = 0;
                for(k = 0; k < A[0].size(); ++k)
                    sum += A[i][k]*B[k][j];
                ans[i][j] = sum;
            }
        return ans;
    }
};