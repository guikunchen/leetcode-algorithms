#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/longest-increasing-subsequence/
// 最多非空子序列为2的n次方-1个，可以采用按位对应法
// 最多非空数组为n(n+1)/2个，起始索引和终止索引，C n选2 + n

// 定义状态转移方程f(n) 即从0到n-1的最长子序列个数
// f(n)的求法就是nums中所有比nums[n-1]小的数的索引，这些索引对应的f中取最大值加1就是f(n)的值。
class Solution {
public:
	// 下面的时间复杂度为n²
    int lengthOfLIS(vector<int>& nums) {
    	int n = (int) nums.size();
    	if(n == 0) return 0;
    	vector<int> dp(n, 0);
    	for(int i = 0; i < n; i++) {
    		dp[i] = 1;
    		for(int j = 0; j < i; j++) {
    			if(nums[j] < nums[i]) {
    				dp[i] = max(dp[i], dp[j] + 1);
    			}
    		}
    	}
    	return *max_element(dp.begin(), dp.end());
    }
    // 用贪婪+二分搜索可以优化到nlogn
    // 贪心的思想为，最长子序列每次添加的元素都是最小的，用d数组来存储，d数组是递增的
    // 如果nums[i]大于d的最后一个元素，直接插入到末尾
    // 否则，替换到d数组中合适的位置
    int lengthOfLIS(vector<int>& nums) {
    	int n = (int) nums.size();
    	if(n == 0) return 0;

    	vector<int> d(1, nums[0]);
    	for(int i = 1; i < n; i++) {
    		if(nums[i] > d.back()) {
    			d.push_back(nums[i]);
    		} else {
    			int low = 0, high = d.size() - 1;
    			int searchResult = -1;
    			while(low <= high) {
    				int middle = low + ((high - low) >> 1);

    				if(d[middle] < nums[i]) {// 找到最后一个比nums[i]小的数
    					searchResult = middle;
    					low = middle + 1;
    				} else {
    					high = middle - 1;
    				}
    			}
    			d[searchResult + 1] = nums[i];
    		}
    	}
    	return d.size();
    }
    
};