#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(unsigned long long num) {
    	if(num < 2) return true;

        unsigned long long l = 2, r = num >> 1;
        while(l <= r) {
            unsigned long long mid = l + ((r-l) >> 1), guessSquared = mid * mid;
            if(guessSquared == num) {
                return true;
            } else if (guessSquared > num) {
                r = mid - 1;
            } else {
            	l = mid + 1;
            }
        }
        return false;
    }
};