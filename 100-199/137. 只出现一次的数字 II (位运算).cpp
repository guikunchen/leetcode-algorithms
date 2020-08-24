// https://leetcode-cn.com/problems/single-number-ii/ 260题

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 画有限自动机，每一位的1叠加三次后变为0，只有那个特别数的1才能够保留
        // 所以有限自动机有0，1，2三种状态，表示某1bit上1的个数
        // 三种状态要用两位来表示。所以，接下来总结转化的规律即可
        int once = 0, twice = 0;
        for(int num : nums){
            once = once ^ num & ~twice;
            twice = twice ^ num & ~once;
        }
        return once;
    }
};