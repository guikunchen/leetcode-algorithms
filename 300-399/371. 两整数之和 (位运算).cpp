#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/sum-of-two-integers/
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry = unsigned(a&b) << 1;// INT_MIN 左移会报错
            a ^= b;
            b = carry;
        }
        return a;
    }
};