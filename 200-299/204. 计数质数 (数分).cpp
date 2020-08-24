// https://leetcode-cn.com/problems/count-primes/

class Solution {
public:
    // 普通的方法是遍历到根号n，最开始可以增加最后一位的判断（是不是2的倍数）

    // 厄拉多塞筛法，2是质数，那么2的所有倍数都不是质数，之后同理
    int countPrimes(int n) {
        vector<bool> signs(n, true);
        int ans = 0;
        for(int i = 2; i <= (int)(sqrt(n)); ++i){// 这里可以优化，只需要执行根号n次，而且判断必须要加等号
            if(signs[i]){
                for (int j = i * i; j < n; j += i){// 这里也是可以优化的，从i * i开始而不是i + i
                    signs[j] = false;
                }
            }
        }
        for(int i = 2; i < n; ++i){
            if(signs[i]){
                ans++;
            }
        }
        return ans;
    }
};