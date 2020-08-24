#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int index = 0, len = str.length();
        bool negative = false;
        while(index<len){
            if(str[index]==' ') {
                ++index;
                continue;
            }
            else if(str[index]=='-'){
                negative = true;
                ++index;
                break;
            }
            else if(str[index]=='+'){
                ++index;
                break;
            }
            else if(str[index]>='0' && str[index]<='9') break;
            else return 0;
        }
        if(index==len) return 0;
        int ans = 0;
        while(str[index]>='0' && str[index]<='9'){
            int single = str[index] - '0';
            if(ans<=(INT_MAX-single)/10) ans = ans * 10 + single;
            else if(negative) return INT_MIN;
            else return INT_MAX;
            index++;
        }
        if(negative) return -ans;
        else return ans;
    }
};

// 负数转化为正数处理

// -2^31 - (2^31-1)
// 1000 0000 0000 0000 表示最小的数，即-2^31

// 避免溢出，如何判断与INT_MAX的关系