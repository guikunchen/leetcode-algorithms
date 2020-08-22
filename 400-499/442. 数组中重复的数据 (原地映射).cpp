// https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
/*给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。

找到所有出现两次的元素。*/
class Solution {// 数组长度为n，元素值限制在[1, n]
public:// 448题
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int tmp;
        for(auto n:nums){
            tmp = abs(n);
            if(nums[tmp-1]<0)// 若为负数代表已经出现过一次，将其对应的值加入到结果中
                ans.push_back(tmp);
            else
                nums[tmp-1] = -nums[tmp-1];// 将出现过的数字对应的下标的数组值设置为负数
        }
        return ans;
    }
};

// 还有一种思路是加上一倍n和两倍n（因为取值是1-N），到时候看值所在区间就能判断出现几次
// 但是这样容易溢出！