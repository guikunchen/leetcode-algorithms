#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        if (x == 0){
            return true;
        }

        vector<int> ints;
        while(x != 0){
            ints.push_back(x % 10);
            x /= 10;
        }
        int i = 0, j = ints.size() - 1;
        while(i <= j){
            if (ints[i] != ints[j]){
                return false;
            }
            i++, j--;
        }
        return true;
    }
};