#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
        	while(i < j && !isornot(s[i])) {
        		i++;
        	}
        	while(i < j && !isornot(s[j])) {
        		j--;
        	}
        	if(i < j) {
        		swap (s[i++],s[j--]);
        	}
        } 
        return s;
    }
    bool isornot(char c) {
        return (c == 'a' || c == 'A' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'e' || c == 'E') ;
    }
};