#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/permutation-sequence/
/*给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213" */
class Solution {
public:
    string getPermutation(int n, int k) {
        // 总共有n!个排列，第一个数字上有n个(n-1)!可能，如果除完结果是0，那么就娶第0个数
        string res;
        string s = string("123456789").substr(0, n);
        --k;
        vector<int> factorials = {0,1,2,6,24,120,720,5040,40320,362880,3628800};
        while(k > 0)
        {
            size_t i = k / factorials[n - 1];// 求出索引
            res.push_back(s[i]);
            s.erase(s.begin() + i);// 去掉用过的数字
            k %= factorials[n - 1];// 更新k
            --n;// 更新n
        }
        return res + s;
    }
};
