#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/interleaving-string/
/*给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
示例 1：

输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true
示例 2：

输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 我们定义 f(i, j) 表示 s1 的前 i 个元素和 s2的前 j 个元素是否能交错组成 s3 的前 i + j个元素。
        auto f = vector < vector <int> > (s1.size() + 1, vector <int> (s2.size() + 1, false));

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n + m != t) {
            return false;
        }

        f[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);// s1[i - 1]是s1的第i个字符
                }
                if (j > 0) {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return f[n][m];
    }
};


class Solution {// 只依赖于前一行，用滚动数组优化
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector <int> (s2.size() + 1, false);

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n + m != t) {
            return false;
        }

        f[0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[j] &= (s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return f[m];
    }
};