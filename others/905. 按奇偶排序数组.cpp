#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/sort-array-by-parity/
// 偶数在前面，奇数在后面
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size() <= 1) return A;

        int begin = 0, end = A.size() - 1;
        while(begin < end) {
            while(begin < end && (A[begin] & 1) == 0) {// 与运算要加括号，优先级太低了
                begin++;
            }
            while(begin < end && (A[end] & 1) == 1) {// 与运算要加括号，优先级太低了
                end--;
            }
            if(begin < end) {
                swap(A[begin], A[end]);
            }
        }
        return A;
    }
};