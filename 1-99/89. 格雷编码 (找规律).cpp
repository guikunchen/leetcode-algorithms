#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/gray-code/
// https://leetcode-cn.com/problems/gray-code/solution/ge-lei-bian-ma-ji-jian-di-gui-fa-by-zoffer/
// G 0 是 0  G1 是 {0, 1}
// 然后G2就是{00, 01, 11, 10}，前面两个是在原来的基础上补0，后面两个是原来的基础上补1再逆序
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray(1, 0);
        int add = 1;
        for(int i = 0; i < n; i++) {
            for(int j = gray.size() - 1; j >= 0; j--) {
                gray.push_back(gray[j] | add);
            }
            add <<= 1;
        }
        return gray; 
    }
};