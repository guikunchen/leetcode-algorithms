#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        string prefix  = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            prefix  = longestCommonPrefix(prefix , strs[i]);// 先比较第一个和第二个，再用共同前缀去比较第三个
            if(prefix.size() == 0) {// 已经没有共同前缀，可以跳出
                break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix(const string & str1, const string & str2) {
        int len = min(str1.size(), str2.size());
        int index = 0;
        while(index < len && str1[index] == str2[index]) {
            index++;
        }
        return str1.substr(0, index);
    }

    // 也可以先排序，比较头尾
    // 也可以求出最短数组的长度，然后二分搜索
    // 也可以用分治，每次把问题规模缩小一半
};