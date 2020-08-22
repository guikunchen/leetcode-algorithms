#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/remove-invalid-parentheses/
class Solution {
public:
    unordered_set<string> sets;

    /*
    * @param s: 源字符串
    * @param index: 当前源字符串索引
    * @param str: 记录结果
    * @param el: 当前可以删除的'('的数量
    * @param er: 当前可以删除的')'的数量
    * @param cntl: 记录当前str中错误的'('的数量
    * @param cntr: 记录当前str中错误的')'的数量
    */
    void dfs(string &s, int index, string &str, int el, int er, int cntl, int cntr){
        // 错误的右括号比左括号多，不管后面接什么，表达式一定错了
        if(cntr > cntl || el < 0 || er < 0) return;
        // 结束条件
        if(index == s.length()){
            if(cntl == 0 && cntr == 0){
                sets.insert(str);
            }
            return;
        }

        // 当前字符不是括号，直接跳过
        if(s[index] != '(' && s[index] != ')'){
            str += s[index];
            dfs(s, index+1, str, el, er, cntl, cntr);
            str.erase(str.length()-1, 1);// 回溯重置状态
        }else{
            // 不删除当前括号，需要记录当前str中错误的左右括号的数量
            str += s[index];
            int cl = cntl, cr = cntr;// 不能修改cntl和cntr，下面删除括号的时候要用
            if(s[index] == '(') cl++;
            else{
                if(cl == 0) cr++;
                else cl--;
            }
            dfs(s, index+1, str, el, er, cl, cr);
            str.erase(str.length()-1, 1);

            // 删除当前括号，修改可删除的左右括号数量
            if(s[index] == '(') --el;
            else --er;
            dfs(s, index+1, str, el, er, cntl, cntr);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;

        // 统计源字符串中无效括号数目
        int el = 0, er = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(') el++;
            else if(s[i] == ')'){
                if(el == 0) er++;
                else el--;
            }
        }

        string str = "";
        dfs(s, 0, str, el, er, 0, 0);

        for(auto it = sets.begin(); it != sets.end(); ++it){
            res.push_back(*it);
        }

        return res;
    }
};