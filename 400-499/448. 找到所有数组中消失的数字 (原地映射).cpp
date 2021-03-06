// https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
/*给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。*/
class Solution {// 442题
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	vector<int> ans;
    	for(auto num : nums) {
    		if(nums[abs(num) - 1] > 0) {
    			nums[abs(num) - 1] = -nums[abs(num) - 1];
    		}
    	}

    	for(int i = 0; i < nums.size(); i++) {
    		if(nums[i] > 0) {// 正数代表没有值映射到这里，负数代表有
    			ans.push_back(i + 1);
    		}
    	}
    	return ans;
    }
};