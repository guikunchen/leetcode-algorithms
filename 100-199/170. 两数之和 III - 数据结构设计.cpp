#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
/*设计并实现一个 TwoSum 的类，使该类需要支持 add 和 find 的操作。

add 操作 - 对内部数据结构增加一个数。
find 操作 - 寻找内部数据结构中是否存在一对整数，使得两数之和与给定的数相等。*/
class TwoSum {
    unordered_map<int,int> m;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            if( (it->first*2 == value && it->second>=2)// 一个数的两倍
                ||(it->first*2 != value && m.find(value-it->first)!=m.end()) )// 差值
                return true;
        }
        return false;
    }
};