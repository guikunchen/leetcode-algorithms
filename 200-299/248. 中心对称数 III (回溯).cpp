#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/strobogrammatic-number-iii/
/*中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
写一个函数来计算范围在 [low, high] 之间中心对称数的个数。*/
class Solution {// def
    vector<string> l = {"0","1","6","8","9"};
    vector<string> r = {"0","1","9","8","6"};
    int ans = 0;
public:
    int strobogrammaticInRange(string low, string high) {
        if(low.size() > high.size() || (low.size()==high.size() && low > high))
            return 0;
        // 第一个包括了所有偶数长度的中心对称数，后三个包含了所有奇数长度的中心对称数
        vector<string> number = {"", "0","1","8"};
        for(int i = 0; i < number.size(); ++i) {
            dfs(number[i], low, high);
        }
        return ans;
    }
    void dfs(string num, string& low, string& high) {
        if(num.size() > high.size())
            return;
        if(num.size()>=low.size() && num.size() <= high.size()) {
            if(num.size()==low.size() && num < low)// 不在区间内
                return;
            if(num.size()==high.size() && num > high)// 不在区间内
                return;
            if(num.size() == 1 || num[0]!='0')// 可以是0，但不能是长度大于1且以0开头的数，后者可以帮助剪枝
                ans++;
        }
        for(int i = 0; i < 5; ++i) {// 遍历所有可能的数
            dfs(l[i]+num+r[i], low, high);
        }
    }
};

class Solution {// bfs，不像dfs一样需要递归
    vector<string> l = {"0","1","6","8","9"};
    vector<string> r = {"0","1","9","8","6"};
    int ans = 0;
public:
    int strobogrammaticInRange(string low, string high) {
        if(low.size() > high.size() || (low.size()==high.size() && low > high))
            return 0;
        queue<string> q;
        q.push("");
        q.push("0");
        q.push("1");
        q.push("8");
        string num;
        while(!q.empty())
        {
            num = q.front();
            q.pop();
            if(num.size() > high.size())
                continue;
            if(num.size()>=low.size() && num.size() <= high.size())
            {
                if(num.size()==low.size() && num < low) 
                    continue;
                if(num.size()==high.size() && num > high)
                    continue;
                if(num.size() == 1 || num[0]!='0')
                    ans++;
            }
            for(int i = 0; i < 5; ++i)
                q.push(l[i]+num+r[i]);
        }
        return ans;
    }
};