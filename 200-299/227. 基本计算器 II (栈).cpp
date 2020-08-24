#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/basic-calculator-ii/
// 比上一题少了括号！就少了递归的步骤！

class Solution {
public:
    int calculate(string s) {
        stack <int> t;
        int res = 0, n = 0;
        char sign = '+';
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] >= '0')  
                n = n * 10 + (s[i] - '0');     //如果是数字，就继续进位
            if(s[i] < '0' && s[i] != ' ' || i == s.size()-1)   // 空格要跳过             
            {    //当遇见新的符号或者是最后一位数字时，进行上一个符号的计算并将结果入栈
                int pre;
                switch(sign)
                {
                    case '+':
                        t.push(n);
                        break;
                    case '-':
                        t.push(-n);
                        break;
                    case '*':
                        pre = t.top();
                        t.pop();
                        t.push(pre * n);
                        break;
                    case '/':
                        pre = t.top();
                        t.pop();
                        t.push(pre / n);
                        break;
                }
                sign = s[i];
                n = 0;              //上个符号的计算结束，符号更新，数字清0
            }
        }
        while(!t.empty())           //统计计算结果
        {
            res += t.top();
            t.pop();
        }
        return res;
    }
};