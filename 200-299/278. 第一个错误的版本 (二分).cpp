#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/first-bad-version/
class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1, end = n;
        while(begin < end) {
            int mid = begin + ((end - begin) >> 1);
            if(isBadVersion(mid)) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        return begin;
    }
};