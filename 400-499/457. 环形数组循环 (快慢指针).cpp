// https://leetcode-cn.com/problems/circular-array-loop/
/*给定一个含有正整数和负整数的环形数组 nums。 如果某个索引中的数 k 为正数，则向前移动 k 个索引。相反，如果是负数 (-k)，则向后移动 k 个索引。因为数组是环形的，所以可以假设最后一个元素的下一个元素是第一个元素，而第一个元素的前一个元素是最后一个元素。

确定 nums 中是否存在循环（或周期）。循环必须在相同的索引处开始和结束并且循环长度 > 1。此外，一个循环中的所有运动都必须沿着同一方向进行。换句话说，一个循环中不能同时包括向前的运动和向后的运动。 */
class Solution {
public:
    int getNextIndex(vector<int>& nums, int index) {
        return (index + nums[index] + 5000*nums.size()) % nums.size();
    }
    // nums中所有元素都不可能是0。这是剪枝可以进行的关键。
    // 遍历时发现某个节点不符合要求，那这个节点之前的节点全部都不可能作为环的一部分，所以可以置为0
    void setZero(vector<int>& nums, int index) {
        int next;
        while(true) {
            next = getNextIndex(nums, index);
            if(nums[next] == 0 || nums[index] * nums[next] < 0) {
                nums[index] = 0;
                break;
            }
            nums[index] = 0;
            index = next;
        }
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return false;

        for(int begin = 0; begin < n; begin++) {
            if(nums[begin] == 0) {
                continue;
            }
            int slow = begin, fast = begin;
            int prevSlow, prevFast;

            while(true) {
                // 慢指针移动一步
                prevSlow = slow;
                slow = getNextIndex(nums, slow);
                // 无环的判断依据
                // 1）当快慢指针指向的新节点发现和上一个节点符号不一致。
                // 2）快慢指针指向了不可能是环中节点的节点(该节点位置已经置0的节点)时。
                // 3）当快慢指针指向的位置不变时。
                if(nums[prevSlow]*nums[slow] < 0 || nums[slow] == 0 || slow == prevSlow) {
                    setZero(nums, begin);
                    break;
                }
                //快指针移动两步
                prevFast = fast;
                fast = getNextIndex(nums, fast);
                if(nums[prevFast]*nums[fast] < 0 || nums[fast] == 0 || fast == prevFast) {
                    setZero(nums, begin);
                    break;
                }
                prevFast = fast;
                fast = getNextIndex(nums, fast);
                if(nums[prevFast]*nums[fast] < 0 || nums[fast] == 0 || fast == prevFast) {
                    setZero(nums, begin);
                    break;
                }
                // 如果快慢指针指向同一个节点代表找到一个环
                if(slow == fast) {
                    return true;
                }
            }
        }
        return false;
    }
};