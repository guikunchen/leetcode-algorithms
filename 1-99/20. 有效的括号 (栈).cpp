#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

// https://leetcode-cn.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {// 非常规做法，不一定非得入栈左括号！
        if((s.size() & 1) == 1) return false;
        stack<char> sta;
        for (char c: s)
        {
            if(c == '('){
                sta.push(')');
            }
            else if(c == '['){
                sta.push(']');
            }
            else if(c == '{'){
                sta.push('}');
            }
            else if(sta.empty() || sta.top() != c){
                return false;
            }
            else{
                sta.pop();
            }
        }
        return sta.empty();
    }
    bool isValid(string s) {// 用hashmap来做，优化了一下时间
        if((s.size() & 1) == 1) return false;// 长度为奇数直接返回false
        map<char, char> hashMap;// 如果在栈底放一个'?'，hashmap里也放个'?'的key，那么就不用每次判断栈空了
        // 也可以用右括号为key，左括号value，设计方式很多
        stack<char> sta;
        hashMap['['] = ']', hashMap['('] = ')', hashMap['{'] = '}';
        for (char c: s)
        {
            if(hashMap.containsKey(c)){
                sta.push(c);
            }
            else if(sta.empty() || hashMap[sta.top()] != c){
                return false;
            }
            else{
                sta.pop();
            }
        }
        return sta.empty();
    }
};