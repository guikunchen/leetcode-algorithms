#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/range-sum-query-immutable/
class NumArray {
private:
    int* sum;
public:
    NumArray(vector<int>& nums) {
        //sum[i] 为 nums[0 : i-1]的和
        sum = new int[nums.size() + 1];
        sum[0] = 0;
        for(int i = 1; i <= nums.size(); i++)
            sum[i] = sum[i - 1] + nums[i - 1];
    }
    ~NumArray(){
        delete[] sum;
    }
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};
