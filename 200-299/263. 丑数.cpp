#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/ugly-number/

class Solution {
public:
    // 如果能整除2，3，5，則把因數除掉，如果都沒有，返回當前值。
    // 如果是丑數，退出循环的时候肯定是1.
    bool isUgly(int num) {
        while(num > 1){
            if(num&1==0) num >> 1;
            else if(num%5==0) num/=5;
            else if(num%3==0) num/=3;
            else break;
        }
        return num==1;
    }
};