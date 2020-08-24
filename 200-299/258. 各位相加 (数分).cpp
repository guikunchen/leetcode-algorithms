#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/add-digits/
// 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
class Solution {
public:
    // x = a1 + a2 * (9+1) + a3 * (99+1) + ...
    // x % 9 = a1 + a2 + a3 + ... + an
    // 所以各个位数之和，等于x % 9
    // 一直求各个位数之和，相当于一直取模9，但注意求余结果是0的话，结果为9
    
    // (-7)/10 = -0.7。求模商向0取值，也就是去掉小数位，因而商取0，所以(-7)-(10*0)=-7，结果是-7。
    // 求余商向负无穷取值，商取-1。 (-7)-(10*1)=3。 好了，结果是3。
    // 有的语言是求模，有的语言是求余，C++是求模
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};