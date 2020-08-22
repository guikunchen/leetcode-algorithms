// https://leetcode-cn.com/problems/split-array-largest-sum/
/*给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。
设计一个算法使得这 m 个子数组各自和的最大值最小。*/

// f[i][j] 表示将数组的前 i 个数分割为 j 段所能得到的最大连续子数组和的最小值。
// 在进行状态转移时，我们可以考虑第 j 段的具体范围，即我们可以枚举 k，
// 其中前 k 个数被分割为 j−1 段，而第 k+1 到第 i 个数为第 j 段。
// 因为分割的子数组不能为空，所以i >= j，所以要把f[0][0]赋值为0

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;// j取1，只分成一段可以转移
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return (int)f[n][m];
    }
};