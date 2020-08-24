#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/peeking-iterator/

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};
// 使用两个变量记录调用next之前是否调用了peek，
// 同时记录上次调用peek结果。
// 如果本次调用peek之前调用了一次peek，则直接返回记录的结果，因此指针此时已经指向了下一个位置
// 如果调用next之前调用了一次peek，返回上次记录的结果，且将上次调用的bool变量设为false
// 如果调用next之前未调用了一次peek，直接返回迭代器的next()，指针此时后移

// 总结起来就是，调用了peek会导致指针后移，但是peek后面紧接着的next应返回peek的结果，所以应该把peek的结果缓存起来
class PeekingIterator : public Iterator {
private:
    bool move;
    int pre;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        move = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!move) {
            move = true;
            pre = Iterator::next();
        }
        return pre;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (move) {
            move = false;
            return pre;
        } else {
            return Iterator::next();
        }
    }

    bool hasNext() const {
        return move || Iterator::hasNext();
    }
};