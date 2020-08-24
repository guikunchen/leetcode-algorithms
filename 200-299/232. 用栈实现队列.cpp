#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

// https://leetcode-cn.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> inS;
    stack<int> outS;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
    	inS.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
    	if(outS.empty()){
    		while(!inS.empty()){// Move the elements of inStack into outStack.
    			int tmp = inS.top();
    			outS.push(tmp);
    			inS.pop();
    		}
    	}
    	int ans = outS.top();
    	outS.pop();
    	return ans;
    }
    
    /** Get the front element. */
    int peek() {
    	if(outS.empty()){
    		while(!inS.empty()){// Move the elements of inStack into outStack.
    			int tmp = inS.top();
    			outS.push(tmp);
    			inS.pop();
    		}
    	}
    	return outS.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
    	return outS.empty() && inS.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */