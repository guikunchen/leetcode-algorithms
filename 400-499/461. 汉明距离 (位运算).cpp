// https://leetcode-cn.com/problems/hamming-distance/

class Solution {
public:
    // 异或结果有几个1，汉明距离就是多少
    int hammingDistance(int x, int y) {
        int yihuo = x ^ y;
        int distance = 0;
            while (yihuo != 0) {
            distance += 1;
            // remove the rightmost bit of '1'
            yihuo = yihuo & (yihuo - 1);
        }
        return distance;
    }
};