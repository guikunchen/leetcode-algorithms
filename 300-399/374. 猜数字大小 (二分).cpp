// https://leetcode-cn.com/problems/guess-number-higher-or-lower/
/*猜数字游戏的规则如下：

每轮游戏，系统都会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。
如果你猜错了，系统会告诉你，你猜测的数字比系统选出的数字是大了还是小了。*/
class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1); //注意：+ 的优先级 高于>>  故对>>操作需要加括号
            int ret = guess(mid);
            if(ret == 0) {
                return mid;
            }
            else if(ret < 0) {
                high = mid - 1;
            }   
            else {
                low = mid + 1;
            }
        }
        return -1;// 找不到
    }
};