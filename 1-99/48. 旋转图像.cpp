#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/rotate-image/
/*给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
] */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix.size() != matrix[0].size()) {
            return;
        }
        int nums = matrix.size();
        int times = 0;
        while(times < (nums >> 1)) {
            int len = nums - (times << 1);// 一层有几个元素
            for(int i = 0; i < len - 1; ++i) {
                // 每层，每次挑四个出来旋转
                int temp = matrix[times][times + i];
                matrix[times][times + i] = matrix[times + len - i - 1][times];
                matrix[times + len - i - 1][times] = matrix[times + len - 1][times + len - i - 1];
                matrix[times + len - 1][times + len - i - 1] = matrix[times + i][times + len - 1];
                matrix[times + i][times + len - 1] = temp;
            }
            ++times;
        }
    }

    // 另一种方法，先沿水平中线上下翻转，再沿对角线反转。
};