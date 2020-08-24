// https://leetcode-cn.com/problems/longest-consecutive-sequence/
/*给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。 */
class Solution {
public:
    unordered_map<int, int> uf, count, rank;

    int find(int index){
        while(index != uf[index]){
            uf[index] = uf[uf[index]];
            index = uf[index];
        }
        return index;
    }

    int unite(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty) return count[rootx];

        int counts = count[rooty] + count[rootx];
        if (rank[rootx] < rank[rooty]) {
            uf[rootx] = rooty;
            count[rooty] = counts;
        }
        else if(rank[rootx] > rank[rooty]){
            uf[rooty] = rootx;
            count[rootx] = counts;
        }
        else{
            uf[rooty] = rootx;
            count[rootx] = counts;
            rank[rootx] += 1;
        }
        return counts;
    }

    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(auto n : nums){
            uf[n] = n;
            count[n] = 1;
            rank[n] = 0;
        }

        int ans = 1;
        for(auto n : nums){
            if(n != INT_MAX && uf.count(n + 1) == 1){
                ans = max(ans, unite(n, n + 1));
            }
        }
        return ans;
    }
};