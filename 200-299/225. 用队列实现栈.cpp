#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/implement-stack-using-queues/

class MyStack {// 双队列或单队列都可以，主要看时间复杂度的限制！
public:
    queue<int> qi; //主队列
    queue<int> qt; //辅助队列
    MyStack() {
    }
    void push(int x) {
        while(qi.size()) { //将qi中的元素全部搬至qt
            qt.push(qi.front());
            qi.pop();
        }
        qi.push(x);  //插入新元素
        while(qt.size()) {  //将qt中的元素全部搬回qi
            qi.push(qt.front());
            qt.pop();
        }
    }
    int pop() {
        int temp = qi.front();
        qi.pop();
        return temp;
    }
    int top() {
        return qi.front();
    }
    bool empty() {
        return qi.empty();
    }
};

class MyStack {
public:
    queue<int> q; //单队列
    MyStack() {
    }
    void push(int x) {
        q.push(x);
        for(int i = 0; i < q.size() - 1; i ++) { //交换位置
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};