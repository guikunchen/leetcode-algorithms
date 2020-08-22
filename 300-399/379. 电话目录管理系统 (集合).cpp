// https://leetcode-cn.com/problems/design-phone-directory
/*设计一个电话目录管理系统，让它支持以下功能：

get: 分配给用户一个未被使用的电话号码，获取失败请返回 -1
check: 检查指定的电话号码是否被使用
release: 释放掉一个电话号码，使其能够重新被分配*/

// 两个哈希set，一个存储没有使用的，一个存储使用过的，来回传递号码
class PhoneDirectory {
    unordered_set<int> unused, used;
    int tel;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for(int i = 0; i < maxNumbers; ++i)
            unused.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(unused.empty()) return -1;
        tel = *unused.begin();
        unused.erase(*unused.begin());
        used.insert(tel);
        return tel;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return unused.find(number) != unused.end();//没有用过
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        used.erase(number);
        unused.insert(number);
    }
};