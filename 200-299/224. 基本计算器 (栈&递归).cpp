#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

// https://leetcode-cn.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
       int begin = 0;
       return calHelper(s, begin);
    }
    int calHelper(string s, int& i) //i用于记录计算开始的索引
    {
        char sign = '+';
        stack<int> nums;
        int num = 0;
        int res = 0;
        bool flag = false;
        for (i; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
             if (s[i] == '(')
            {
                num = calHelper(s, ++ i); // 从i的下一个开始计算， 进入递归
                i++; // 计算完之后的i指向)所以再++
            }
            if (((s[i] < '0' || s[i] > '9') && s[i] != ' ') || i >= s.size() - 1) // 继续计算
            {
                int pre = 0;
                switch (sign)
                {
                case '+': nums.push(num);
                    break;
                case '-': nums.push(-num);
                    break;
                case '*':
                    pre = nums.top();
                    nums.pop();
                    nums.push(pre * num);
                    break;
                case '/':
                    pre = nums.top();
                    nums.pop();
                    nums.push(pre / num);
                    break;
                }

                sign = s[i];
                num = 0;
            }
            if (s[i] == ')') // 遇到)回到上一级递归
            {
                break;
            }
        }
        while (!nums.empty())
        {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};

class Solution {
public:
    // 把负数转成正数来处理，用栈保存结果
    int calculate(string s) {
        stack<int> ans;
        int sign = 1;
        int operand = 0;
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+'){
                result += sign * operand;
                sign = 1;
                operand = 0;
            }
            else if(s[i] == '-'){
                result += sign * operand;
                sign = -1;
                operand = 0;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                operand = operand * 10 - '0' + s[i]; 
            }
            else if(s[i] == '('){
                ans.push(result);
                ans.push(sign);

                sign = 1;
                result = 0;
            }
            else if(s[i] == ')'){
                result += sign * operand;

                result *= ans.top();
                ans.pop();
                result += ans.top();
                ans.pop();

                sign = 1;// 可要可不要，反正乘完结果等于0（右括号后面一定跟'+'或者'-'）
                operand = 0;
            }
        }
        return result + sign * operand;
    }


    // 下面这种做法是通用的，转后缀式再求值
    // 其实可以用双栈，一个存操作数一个存操作符，边遍历的时候边计算，这样优化了一些
    enum signs {PLUS = -1, MINUS = -2};
    int calculate(string s) {
        stack<char> tmp;
        queue<int> poster;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == ' '){
                continue;
            }
            else if(s[i] == ')'){
                while(tmp.top() != '('){
                    switch(tmp.top()){
                        case '+': poster.push(PLUS); break;
                        case '-': poster.push(MINUS); break;
                        default: break;
                    }
                    tmp.pop();
                }
                tmp.pop();
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                int number = s[i] - '0';
                while(i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9'){
                    ++i;
                    number = number * 10 - '0' + s[i] ;
                }
                poster.push(number);
            }
            else if(s[i] == '('){
                tmp.push(s[i]);
            }
            else{
                while(!tmp.empty() && tmp.top() != '('){
                    switch(tmp.top()){
                        case '+': poster.push(PLUS); break;
                        case '-': poster.push(MINUS); break;
                        default: break;
                    }
                    tmp.pop();
                }
                tmp.push(s[i]);
            }
        }
        while(!tmp.empty()){
            switch(tmp.top()){
                case '+': poster.push(PLUS); break;
                case '-': poster.push(MINUS); break;
                default: break;
            }
            tmp.pop();
        }
        stack<int> ans;
        while(!poster.empty()){
            int current = poster.front();
            poster.pop();
            if(current >= 0){
                ans.push(current);
            }
            else{
                int top = ans.top();
                ans.pop();
                int bottom = ans.top();
                ans.pop();
                switch(current){
                    case PLUS: ans.push(bottom + top); break;
                    case MINUS: ans.push(bottom - top); break;
                    default: break;
                }
            }
        }
        return ans.top();
    }
};