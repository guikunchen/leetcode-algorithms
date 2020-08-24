#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {// 后缀表达式求值，很容易，有些地方或许能优化一点点
    	stack<int> s;
    	for(string token:tokens){
    		if(token == "+"){
    			int top = s.top();
	    		s.pop();
	    		int bottom = s.top();
	    		s.pop();
    			s.push(bottom + top);
    		}
    		else if(token == "-"){
    			int top = s.top();
	    		s.pop();
	    		int bottom = s.top();
	    		s.pop();
    			s.push(bottom - top);
    		}
    		else if(token == "*"){
    			int top = s.top();
	    		s.pop();
	    		int bottom = s.top();
	    		s.pop();
    			s.push(bottom * top);
    		}
    		else if(token == "/"){
    			int top = s.top();
	    		s.pop();
	    		int bottom = s.top();
	    		s.pop();
    			s.push(bottom / top);
    		}
    		else{
    			s.push(atoi(token.c_str()));
    		}
    	}
    	return s.top();
    }
};