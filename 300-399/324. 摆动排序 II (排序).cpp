#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/wiggle-sort-ii/  280题

class Solution {
public:
    // 第一种方法是先排序，然后从中间切开得到A,B两个子数组，
    // 如果A的末尾和B的前面有重复元素，且重复个数 == (len(nums)+1)/2，穿插后会不满足性质
    // 解决办法是A和B都进行逆转，再进行穿插，就解决了。 如果重复个数大于它，问题就无解。
    // 这样时间nlogn 空间n

    // 第二种方法，快速选择算法找到中位数，https://zhuanlan.zhihu.com/p/64627590
    // 然后3-way-partition，分割为 小 中位数 大，三个部分
    // 然后逆序放进去就可以了，时间n，空间n
    void wiggleSort(vector<int>& nums) {
        auto midptr = nums.begin() + (nums.size() >> 1);
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // 3-way-partition
        int i = 0, j = 0, k = nums.size() - 1;
        while(j <= k){
            if(nums[j] > mid){
                swap(nums[j], nums[k]);
                k--;
            }
            else if(nums[j] < mid){
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        if(nums.size() & 1 == 1){// 是奇数
            midptr++;// 抄的，不知道这一步干嘛，感觉没影响，找到真正的中位数？
        }
        // 存在两个临时数组，再穿插放回去
        vector<int> tmp1(nums.begin(), midptr);
        vector<int> tmp2(midptr, nums.end());
        for(int i = 0; i < tmp1.size(); i++){
            nums[i << 1] = tmp1[tmp1.size() - 1 - i];// 逆序
        }
        for(int i = 0; i < tmp2.size(); i++){
            // 要注意运算符优先级，这个括号必须加
            nums[(i << 1) + 1] = tmp2[tmp2.size() - 1 - i];// 逆序
        }
    }

    // 基于上面的解法，使用虚拟索引将空间优化为1
    // Accessing A(0) actually accesses nums[1].
    // Accessing A(1) actually accesses nums[3].
    // Accessing A(2) actually accesses nums[5].
    // Accessing A(3) actually accesses nums[7].
    // Accessing A(4) actually accesses nums[9].
    // Accessing A(5) actually accesses nums[0].
    // Accessing A(6) actually accesses nums[2].
    // Accessing A(7) actually accesses nums[4].
    // Accessing A(8) actually accesses nums[6].
    // Accessing A(9) actually accesses nums[8].
    // 然后把大的放左边，小的放右边，3-way-partition完，就得到了问题的解
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        auto midptr = nums.begin() + (n >> 1);
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // 这个映射跟个鬼一样，谁想得出来
        #define A(i) nums[(1 + (i << 1)) % (n | 1)]

        // 3-way-partition
        int i = 0, j = 0, k = n - 1;
        while(j <= k){
            if(A(j) > mid){
                swap(A(j), A(i));
                i++;
                j++;
            }
            else if(A(j) < mid){
                swap(A(j), A(k));
                k--;
            }
            else{
                j++;
            }
        }
    }
};