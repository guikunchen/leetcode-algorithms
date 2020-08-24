#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/edit-distance/
/*给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e') */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // DP 数组
        int D[n + 1][m + 1];

        // 边界状态初始化
        for (int i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }

        // 计算所有 DP 值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int top = D[i - 1][j] + 1;// 在B末尾添加一个字符
                int left = D[i][j - 1] + 1;// 在A末尾添加一个字符
                int left_top = D[i - 1][j - 1];// 需要修改A字符
                if (word1[i - 1] != word2[j - 1]) left_top += 1;// 字符不相同就要修改
                D[i][j] = min(top, min(left, left_top));
            }
        }
        return D[n][m];
    }
};