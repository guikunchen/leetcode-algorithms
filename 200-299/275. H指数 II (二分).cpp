#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/h-index-ii/
/*h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）"
输入: citations = [0,1,3,5,6]
输出: 3 
解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
     由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。*/
// 这是 H指数 的延伸题目，本题中的 citations 数组是保证有序的。
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int begin = 0, end = n - 1;
        while(begin <= end) {
            int mid = begin + ((end - begin) >> 1);
            if(citations[mid] < n - mid) {
                begin = mid + 1;
            } else if(citations[mid] > n - mid) {
                end = mid - 1;
            } else {// 刚好相等
                return n - mid;
            }
        }
        return n - begin;
    }
};