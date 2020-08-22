#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/logger-rate-limiter
/*请你设计一个日志系统，可以流式接收日志以及它的时间戳。
该日志会被打印出来，需要满足一个条件：当且仅当日志内容 在过去的 10 秒钟内没有被打印过。
给你一条日志的内容和它的时间戳（粒度为秒级），如果这条日志在给定的时间戳应该被打印出来，则返回 true，否则请返回 false。
要注意的是，可能会有多条日志在同一时间被系统接收。
示例：
Logger logger = new Logger();
// 日志内容 "foo" 在时刻 1 到达系统
logger.shouldPrintMessage(1, "foo"); returns true; 
// 日志内容 "bar" 在时刻 2 到达系统
logger.shouldPrintMessage(2,"bar"); returns true;
// 日志内容 "foo" 在时刻 3 到达系统
logger.shouldPrintMessage(3,"foo"); returns false;
// 日志内容 "bar" 在时刻 8 到达系统
logger.shouldPrintMessage(8,"bar"); returns false;
// 日志内容 "foo" 在时刻 10 到达系统
logger.shouldPrintMessage(10,"foo"); returns false;
// 日志内容 "foo" 在时刻 11 到达系统
logger.shouldPrintMessage(11,"foo"); returns true;*/

class Logger {
    unordered_map<string,int> m;
public:
    /** Initialize your data structure here. */
    Logger() {

    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.find(message) == m.end() || timestamp-m[message]>=10) {// 不存在，或距离上一次打印时间不低于10
            m[message] = timestamp;
            return true;// 打印
        }
        else
            return false;// 不打印
    }
};