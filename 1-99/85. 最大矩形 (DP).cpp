#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/maximal-rectangle/
// 转化为柱状图，又转化为84题
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;

        int maxArea = 0;
        vector<int> dp(matrix[0].size(), 0);
        int rows = matrix.size(), columns = matrix[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                // 从上往下看，以matrix[i][j]结束的最大宽度
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            // 通过一行的柱状图算出最大矩形，更新结果
            maxArea = max(maxArea, largestRectangleArea(dp));
        }
        return maxArea;
    }
    int largestRectangleArea(vector<int>& heights) {// 调用84题代码
        int n = heights.size();
        vector<int> left(n), right(n, n);
        
        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {// 用等于号是因为，如果有连续多个等高的柱，最右边的那个可以得到正确答案（其他的都得不到）
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;

        int maxArea = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> height(columns, 0);
        vector<int> left(columns, 0);
        vector<int> right(columns, columns);
        // left 和 right 是左闭右开区间
        for(int i = 0; i < rows; i++) {
            int cur_left = 0, cur_right = columns;
            for(int j = 0; j < columns; j++) {
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            }
            for(int j = 0; j < columns; j++) {
                if(matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                } else {
                    left[j] = 0, cur_left = j + 1;
                }
            }
            for(int j = columns - 1; j >= 0; j--) {
                if(matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = columns, cur_right = j;
                }
            }
            for(int j = 0; j < columns; j++) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }
        return maxArea;
    }
};