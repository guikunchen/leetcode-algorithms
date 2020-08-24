#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/palindrome-permutation
/*给定一个字符串，判断该字符串中是否可以通过重新排列组合，形成一个回文字符串。
*/
class Solution {
public:// 奇数种类的字符 <= 1
    bool canPermutePalindrome(string s) {
    	vector<int> c(128,0);
    	for(char ch : s)
    		c[ch]++;
    	int odd = 0;
    	for(int i = 0; i < 128; ++i)
    		if(c[i]&1)
    			odd++;
		return odd <= 1;
    }
};