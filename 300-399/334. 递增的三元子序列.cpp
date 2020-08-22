#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/increasing-triplet-subsequence/

// 可以正序单调递增栈一遍，逆序单调递减栈一遍，就能知道有没有了。

// 下面是贪心算法
/*假如当前的 small 和 mid 为 [3, 5]，这时又来了个 1。
假如我们不将 small 替换为 1，那么，当下一个数字是 2，后面再接上一个 3 的时候，
我们就没有办法发现这个 [1,2,3] 的递增数组了！也就是说，我们替换最小值，
是为了后续能够更好地更新中间值！

另外，即使我们更新了 small ，这个 small 在 mid 后面，没有严格遵守递增顺序，
但它隐含着的真相是，有一个比 small 大比 mid 小的前·最小值出现在 mid 之前。
因此，当后续出现比 mid 大的值的时候，
我们一样可以通过当前 small 和 mid 推断的确存在着长度为 3 的递增序列。 
所以，这样的替换并不会干扰我们后续的计算！
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() <= 2) return false;

        int small, mid;
        small = mid = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= small) {
                small = nums[i];
            } else if(nums[i] <= mid) {
                mid = nums[i];
            } else if(nums[i] > mid) {
                return true;
            }
        }
        return false;
    }
};