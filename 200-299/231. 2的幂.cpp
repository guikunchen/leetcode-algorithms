#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/power-of-two/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        long long x = n;
        return (x & (x - 1)) == 0;// INT_MIN 再减一会报错
    }
};