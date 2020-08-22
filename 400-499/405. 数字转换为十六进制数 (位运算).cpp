// https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/

// 但右移4位对于负数有个问题，负数补码最高位为1，移位后会补1，不会变0，因此用一个p来计数，只移动8次。
// 至于为什么不正负数都直接循环8次，正数要用判零，是因为转十六进制高位都是0的话，
// 正数固定循环8次就会在高位补零，这是不允许的。而对于负数，最高位肯定是1，不会出现高位都是零的情况。

class Solution {
public:
    string toHex(int num) {
        string r = ""; int p = -1;
        string hex[16]={"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
        if (num == 0) return "0";
        else if (num <0) p=8;
        while (num) {
            if (p == 0) break;
            int c = 0;
            c = (num & 0x0000000f);
            r = hex[c] + r;
            num >>= 4;
            --p;
        }
        return r;
    }
};