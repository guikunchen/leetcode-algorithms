#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/read-n-characters-given-read4-ii/

// 这个题目的意思是调用read4读取数据，但一次读取4个，若文件中最后不够4个了，
// 则把最后的都读了；所以在read(buf,n)的时候，就需要处理，多读，和文件读完的情况；
// 

// 前一题直接读取到buf；这题要先读取到temp，再把temp赋值给buf
int read4(char *buf);

class Solution {
public:

    char* temp = new char[4];
    int index = 0;
    int count = 0;
    
    int read(char *buf, int n) {
        int i = 0;
        while(i < n){
            if(index == 0)
                count = read4(temp);
            if(count == 0)
                break;
            while(i < n && index < count)
                buf[i++] = temp[index++];
            if(index >= count)
                index = 0;
        }
        return i;
    }
};