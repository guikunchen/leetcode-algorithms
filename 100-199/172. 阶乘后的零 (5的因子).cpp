#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/factorial-trailing-zeroes/

class Solution {
public:
	// 偏向于数学题
	// 偶数的个数比5的个数多，所以只要找5就可以。
	// 每隔5就要加一次0，那么就有 n/5 个 0
	// 但是25可以拆出来两个5，所以在原来的基础上再加 n / 25
	// 同理，125可以拆出来三个5，在上一步基础上加 n / 125
    int trailingZeroes(int n) {
    	int count = 0;
	    while (n > 0) {
	        count += n / 5;
	        n = n / 5;
	    }
	    return count;
    }
};