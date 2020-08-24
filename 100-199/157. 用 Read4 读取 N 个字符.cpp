#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/read-n-characters-given-read4/

/** buf是一个指针，每次读取不能覆盖原来的地方，需要偏移4，
**/
int read4(char *buf);// 返回实际读取的数量

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int cnt = 0, res = 0, tmp = n;
        while (tmp > 0) {
            res += read4(buf + (cnt++ * 4));
            tmp -= 4;
        }
        return res < n ? res: n;// 如果实际读取的数量比n小，要返回读取的值，反之返回n原先的值
    }
};