#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        while(index >= 0) {
            if(digits[index] == 9) {
                digits[index] = 0;
            } else {
                digits[index]++;
                return digits;
            }
            index--;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};