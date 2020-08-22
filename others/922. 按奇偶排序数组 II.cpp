#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/sort-array-by-parity-ii/
// 奇数放在奇数索引，偶数放在偶数索引

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if(A.size() <= 1) return A;

        int odd = 1, n = A.size();
        for(int even = 0; even < n; even += 2) {
            if((A[even] & 1) == 1) {
                while(odd < n && (A[odd] & 1) == 1) {
                    odd += 2;
                }
                swap(A[even], A[odd])
            }
        }
        return A;
    }
};