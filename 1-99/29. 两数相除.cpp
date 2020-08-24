#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/divide-two-integers/
/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
示例 1:

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333..) = -2*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend>INT_MIN) 
                return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            else 
                return INT_MAX;// 是最小的那个，那就返回最大的整数啦
        }
        int sign = 1; 
        if((dividend>0&&divisor<0) || (dividend<0&&divisor>0)){
            sign = -1;
        }
        dividend=-abs(dividend);//都转换为负数，避免溢出
        divisor=-abs(divisor);
        int res = div(dividend,divisor);
        if(sign>0)
            return res;
        else
            return -res;
    }
    int div(long a, long b){  // 似乎精髓和难点就在于下面这几句
        if(a>b) return 0;
        int count = 1;
        int tb = b; // 在后面的代码中不更新b
        while((tb-a+tb)>=0){
            count = count + count; // 最小解翻倍
            tb = tb+tb; // 当前测试的值也翻倍
        }
        return count + div(a-tb,b);
    }
};