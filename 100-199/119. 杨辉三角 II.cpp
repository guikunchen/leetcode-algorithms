#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/pascals-triangle-ii/
// 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> kRows(rowIndex+1);//第K行的vector大小为 rowIndex+1
        for(int i = 0; i <= rowIndex; i++)//利用前一行求后一行，第K行要循环K遍
        {
            kRows[i] = 1;//行末尾为1
            for(int j = i; j > 1; j--)//每一行的更新过程
            {
                kRows[j-1] = kRows[j-2] + kRows[j-1];
            }
        }
        return kRows;   
    }
};