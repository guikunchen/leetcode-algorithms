#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/h-index/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 排序（注意这里是升序排序，因此下面需要倒序扫描）
        sort(citations.begin(), citations.end());
        // 线性扫描找出最大的 i，也可以二分查找，但不会影响复杂度
        int i = 0, n = citations.size();
        while(i < n && citations[n - 1 - i] > i) {
            i++;
        }
        return i;
    }

    // 空间换时间
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> beyond(n + 1, 0);// beyond[i]表示引用数>=i的论文数量
        for(auto citation : citations) {
            beyond[min(citation, n)]++;
        }
        int k = n;
        for(int sum = beyond[n]; k > sum; k--) {
            sum += beyond[k - 1];
        }
        return k;
    }
};