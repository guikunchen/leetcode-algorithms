#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

// https://leetcode-cn.com/problems/min-stack/

// 使用辅助栈（同步的方式，即两个栈元素个数相等）

// 不同步的方式就是个数不相等
// 只有出栈元素和辅助栈元素相等的时候，辅助栈才出栈
// 只有入栈元素小于等于辅助栈栈顶的时候才入辅助栈
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        s = new stack<int>();
        helper = new stack<int>();
    }
    
    void push(int x) {
        s->push(x);
        if(helper->empty() || helper->top() > x){
            helper->push(x);
        }
        else{
            helper->push(helper->top());
        }
    }
    
    void pop() {
        s->pop();
        helper->pop();
    }
    
    int top() {
        return s->top();
    }
    
    int getMin() {
        return helper->top();
    }
private:
    stack<int> *s;
    stack<int> *helper;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */