#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/search-a-2d-matrix/ 第二题240

class Solution {
  public:
  // 整个矩阵实际上就是一个排序数组，直接二分查找就OK
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    // 二分查找
    int left = 0, right = m * n - 1;
    int pivotIdx, pivotElement;
    while (left <= right) {
      pivotIdx = (left + right) / 2;
      pivotElement = matrix[pivotIdx / n][pivotIdx % n];
      if (target == pivotElement) return true;
      else {
        if (target < pivotElement) right = pivotIdx - 1;
        else left = pivotIdx + 1;
      }
    }
    return false;
  }
};

class Solution {
public:
	// 剑指offer的方法，但是这道题目条件加强了，可以用二分查找
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int rows=matrix.size();
        int cols=matrix[0].size();
        bool found=false;
        if(rows>0 && cols>0)
        {
            // 从第一行最后一个数开始比较
            int row=0;
            int col=cols-1;
            while(row<rows && col>=0)
            {
                if(matrix[row][col]==target)// 找到，返回true
                {
                    found=true;
                    break;
                }
                else if(matrix[row][col]>target)// 当前比target大，此时当前列不符合条件，后退一列
                   --col;
                else// 当前比target小，此时当前行不符合条件，往下一行
                    ++row;
            }

        }
        return found;
    }
};