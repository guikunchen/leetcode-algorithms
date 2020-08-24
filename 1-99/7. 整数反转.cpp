#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN)
            return 0;
        if(x<0)
            return -reverse(-x);
        int res=0;
        while(x){
            int single=x%10;
            if(res<=(INT_MAX-single)/10){
                res*=10;
                res+=single;
                x/=10;
            }
            else{
                return 0;
            }
        }
        return res;
    }
};

// 负数转化为正数处理

// -2^31 - (2^31-1)
// 1000 0000 0000 0000 表示最小的数，即-2^31

// 避免溢出，如何判断与INT_MAX的关系