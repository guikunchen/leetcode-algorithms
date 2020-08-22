// https://leetcode-cn.com/problems/integer-replacement/
/*给定一个正整数 n，你可以做如下操作：

1. 如果 n 是偶数，则用 n / 2替换 n。
2. 如果 n 是奇数，则可以用 n + 1或n - 1替换 n。
n 变为 1 所需的最小替换次数是多少？*/
class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) // 处理溢出，也可以直接用long tmp = n；
            return 32;// 先加1变成2的31次方，然后31次除2
        int count = 0;
        while (n != 1) {
            if ((n & 1) == 0) { // 偶数直接右移
                n>>=1;
            }else {
                // 显然，让每一步1的数目最少好处大
                // 奇数 01减一,11加1,特殊情况n=3也是减1
                n += ((n & 2) == 0 || n == 3)? -1:1;
            }
            count++;
        }
        return count;
    }
};