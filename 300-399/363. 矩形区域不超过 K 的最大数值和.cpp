#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        if (row==0)
            return 0;
        int column=matrix[0].size();
        int ans=INT_MIN;
        for (int left=0;left<column;++left)// 固定左边界
        {
            vector<int> row_sum(row,0);// 每一行左右边界内所有元素的和
            for (int right=left;right<column;++right)// 固定右边界
            {
                for (int i=0;i<row;++i)// 计算每一行的rowSum
                    row_sum[i]+=matrix[i][right];
                // 从rowSum里找出最接近k的数（小于等于k）
                ans=max(ans,maxSumSubmatrix_helper(row,row_sum,k));
                if(ans == k) return ans;// 提前返回
            }
        }
        return ans;
    }
    int maxSumSubmatrix_helper(const int &row,vector<int>& row_sum,const int &k)
    {
        int helper_sum=row_sum[0],max_sum=helper_sum;
        for (int i=1;i<row;++i)
        {
            if (helper_sum<=0)
                helper_sum=row_sum[i];
            else
                helper_sum+=row_sum[i];
            if (helper_sum>max_sum)
                max_sum=helper_sum;
        }
        if (max_sum<=k)// 因为是矩形所以要连续，子序列可以不连续，所以求的是最大子数组的和
            return max_sum;// 如果最大子数组的和小于等于k可以直接返回，这样时间复杂度n
        max_sum=INT_MIN;// 不行的话只能暴力求最接近k的值了，消耗n²
        for (int i=0;i<row;++i)
        {
            int sum=0;
            for (int j=i;j<row;++j)
            {
                sum+=row_sum.at(j);
                if (sum==k)
                    return k;
                if (sum<=k && sum>max_sum)
                    max_sum=sum;
            }
        }
        return max_sum;
    }
};