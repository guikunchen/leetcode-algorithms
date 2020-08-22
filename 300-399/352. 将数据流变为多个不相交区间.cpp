#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/

// 初始为一个空区间。
// 每次输入一个数据 val 时，插入一个 [val, val] 区间。
// 合并相邻的区间。
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(const int val) {
        vector<int> newInterval{val, val};
        auto it = intervals.begin();
        while (it != intervals.end()) {
        	// 如果是 1 3 7 2
        	// 2的时候把区间变成了1-3，插到左边就退出，没有放到末尾
            if (newInterval[1] + 1 < (*it)[0]) {// 在迭代器的左边插入一个节点
                intervals.insert(it, newInterval);
                return;
            } else if ((*it)[1] + 1 < newInterval[0]) {// it的右端点+1 比 new的左端点小
                it++;// 放在it的后面
            } else {// 合并在it的左边或者右边
                newInterval[0] = min(newInterval[0], (*it)[0]);
                newInterval[1] = max(newInterval[1], (*it)[1]);
                it = intervals.erase(it);// 指向被删除元素的下一个元素
            }
        }
        intervals.push_back(newInterval);//（除非末尾的区间被合并，不然不会执行这一句）
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
    
private:
    vector<vector<int>> intervals;
};