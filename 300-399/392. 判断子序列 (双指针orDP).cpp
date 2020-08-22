// https://leetcode-cn.com/problems/is-subsequence/

class Solution {// 双指针贪心判断一下就好了
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
};

class Solution {// 动态规划对t进行预处理，适用于s特别多的情况
public:
    /*令 f[i][j] 表示字符串 t 中从位置 i 开始往后字符 j 第一次出现的位置。
    在进行状态转移时，如果 t 中位置 i 的字符就是 j，那么 f[i][j]=i，
    否则 j 出现在位置 i+1 开始往后，即 f[i][j]=f[i+1][j]，
    因此我们要倒过来进行动态规划，从后往前枚举 i。*/
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int> > f(m + 1, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            f[m][i] = m;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (t[i] == j + 'a')
                    f[i][j] = i;
                else
                    f[i][j] = f[i + 1][j];
            }
        }
        int add = 0;
        for (int i = 0; i < n; i++) {
            if (f[add][s[i] - 'a'] == m) {
                return false;
            }
            add = f[add][s[i] - 'a'] + 1;
        }
        return true;
    }
};