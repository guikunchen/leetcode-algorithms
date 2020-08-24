#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。 */
// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
/*首先我们枚举某一根柱子 i 作为高 h=heights[i]；

随后我们需要进行向左右两边扩展，使得扩展到的柱子的高度均不小于 h。
换句话说，我们需要找到左右两侧最近的高度小于 h 的柱子，
这样这两根柱子之间（不包括其本身）的所有柱子高度均不小于 h，
并且就是 i 能够扩展到的最远范围。
。*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
//我们确实无法求出正确的右边界，但对最终的答案没有任何影响。
// 这是因为在答案对应的矩形中，如果有若干个柱子的高度都等于矩形的高度，
// 那么最右侧的那根柱子是可以求出正确的右边界的，
// 而我们没有对求出左边界的算法进行任何改动，
// 因此最终的答案还是可以从最右侧的与矩形高度相同的柱子求得的。
// 23332
// 第一个3 left = 0 right = 2
// 第二个3 left = 0 right = 3
// 第三个3 left = 0 right = 4