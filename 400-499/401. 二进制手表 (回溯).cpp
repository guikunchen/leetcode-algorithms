// https://leetcode-cn.com/problems/binary-watch/

/* 二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。
每个 LED 代表一个 0 或 1，最低位在右侧。
给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。
*/
class Solution {
public:
    vector<string>res;
    unordered_map<int,int> hash={{0,1},{1,2},{2,4},{3,8},{4,1},{5,2},{6,4},{7,8},{8,16},{9,32}};
    void backtrack(int num,int start,pair<int,int>& time) {
        if(num == 0) {// 可用1的数量降到0
            if(time.first>11 || time.second > 59)//判断合法性
                return;
            string temp_hour=to_string(time.first);
            string temp_minute=to_string(time.second);
            if(temp_minute.size()==1)//如果minute只有一位要补0
                temp_minute.insert(0,"0");
            res.push_back(temp_hour+":"+temp_minute);//构造格式
            return;
        }
    
        for(int i=start;i<10;i++) {
            if(time.first>11||time.second>59)
                continue;
            pair<int,int> store = time;//保存状态
            if(i<4)// 小时是[0,3] 分钟是[4,9]
                time.first+=hash[i];
            else
                time.second+=hash[i];
            backtrack(num-1,i+1,time);//进入下一层，注意下一层的start是i+1，即从当前灯的下一盏开始
            time=store;//恢复状态
        }
    }
    vector<string> readBinaryWatch(int num) {
        pair<int,int> time(0,0);//初始化时间为0:00
        backtrack(num,0,time);
        return res;
    }
};

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        // 直接遍历  0:00 -> 11:99   计算每个时间有多少1
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (count1(i) + count1(j) == num) {
                    res.push_back(to_string(i)+":"+
                                  (j < 10 ? "0"+to_string(j) : to_string(j)));
                }
            }
        }
        return res;
    }
    // 计算二进制中1的个数
    int count1(int n) {
        int res = 0;
        while (n != 0) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};