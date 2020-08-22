#include<iostreeeam>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/range-sum-query-mutable/
// 树状数组https://www.bilibili.com/video/BV1pE41197Qj
// 令第i个位置记录(i - lowbit(i), i]中的数字的合
// 一个节点的子节点，由小到大依次覆盖区间(i - lowbit(i), i)
// 一个位置i，只会被节点i及其祖先节点覆盖
class NumArray {
public:
    
    vector<int> tree;
    int n;
    vector<int> data;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i ++) {
            add(i + 1, nums[i]);
        }
        data = nums;
    }
    
    int lowbit(int x) {
        return x & -x;
    }
    
    int sum(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tree[i];
        // 比如t[7] = t[7] + t[6] + t[4]
        return res;
    }
    
    void add(int x, int c) {// 以x为根节点，一直到最顶层父节点，每个都加上一个值
        for (int i = x; i <= n; i += lowbit(i)) tree[i] += c;
    }
    
    void update(int i, int val) {
        add(i + 1, val - data[i]);// 该节点的所有父节点都要加上差值
        data[i] = val;
    }
    
    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */