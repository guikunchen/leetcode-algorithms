#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/sort-transformed-array
/*给你一个已经 排好序 的整数数组 nums 和整数 a、b、c。对于数组中的每一个数 x，计算函数值 f(x) = ax^2 + bx + c，请将函数值产生的数组返回。

要注意，返回的这个数组必须按照 升序排列，并且我们所期望的解法时间复杂度为 O(n)。

示例 1：
输入: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
输出: [3,9,15,33]

示例 2：
输入: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
输出: [-23,-5,1,7]*/

// a = 0，函数单调，直接求值，检查首尾是否升序，降序则进行反转
// a != 0，找到离抛物线对称轴最近的点，依距离近的优先，向两侧扩展，最后检查是否需要反转
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> ans(n);
        if(a == 0) {
            for(int i = 0; i < n; ++i)
                ans[i] = f(nums[i],a,b,c);
            if(ans[0] > ans[n-1])
                reverse(ans.begin(),ans.end());
            return ans;
        }

        double axis = -b/(2.0*a);
        int l = 0, r = 1;// l 和 r 是最接近对称轴的两个点
        if(axis <= nums[0]) l = -1, r = 0;
        else if(axis >= nums[n-1]) l = n-1, r = n;
        else {
            while(nums[l]<axis)
                l++;
            l--, r = l+1;
        }
        
        double disl, disr;
        int i = 0;
        while(l>=0 || r<n) {// 从对称轴两侧选点加到答案数组的末尾，这样添加一定是有序的
            disl = (l>=0)? fabs(nums[l]-axis) : LONG_MAX;
            disr = (r<n)? fabs(nums[r]-axis) : LONG_MAX;
            if(disl < disr) {
                ans[i++] = f(nums[l],a,b,c);
                l--;
            } 
            else {
                ans[i++] = f(nums[r],a,b,c);
                r++;
            }
        }
        if(ans[0] > ans[n-1])
            reverse(ans.begin(),ans.end());// 降序变升序
        return ans;
    }

    int f(int x, int a, int b, int c) {
        return a*x*x+b*x+c;
    }
};