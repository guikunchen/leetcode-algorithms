#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/restore-ip-addresses/

class Solution {
public:
    vector<string> res;

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        string cur = s;
        backtrack(n, 0, -1, cur, s);
        return res;
    }

    void backtrack(int size, int pointnum, int lastpoint, string& cur, string& s) {
        //pointnum记录目前加了几个点了，lastpoint记录上一个点加的位置
        if (pointnum == 3) {
        //如果已经加了三个点了，并且最后一个点的右边表示的数小于255，则是正确IP地址
            if (valid(lastpoint + 1, size - 1, s)){
                res.push_back(cur);
            }
            return;
        }
        //从上一个.号的下一个位置开始查找
        for (int i = lastpoint + 1; i < min(lastpoint + 4, size - 1); i++) {
            //如果字符串s从上一个.号到i位置表示的数小于等于255，则符合条件
            if (valid(lastpoint + 1, i, s)) {
                //正常回溯法，注意这里要+pointnum，因为已经加入的.号也会占位
                cur.insert(cur.begin() + i + pointnum + 1, '.');
                backtrack(size, pointnum + 1, i, cur, s);
                cur.erase(pointnum + i + 1, 1);
            }
        }
        return;
    }

    bool valid(int left, int right, string& s) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            if (left != right && s[left] == '0' ) return false;
            sum = sum * 10 + (s[i] - '0');// 计算[left, right]是否处于[0, 255]，且不能是0xx
            if (sum > 255) return false;
        }
        return true;
    }
};