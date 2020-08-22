// https://leetcode-cn.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hm;
        for(auto c: s) hm[c]++;
        for(auto c: t){
            if(hm[c]-- == 0) return c;
        }
        return '0';// 为了编译能通过
    }

    // 还可以用异或，这个操作比较骚，异或符合交换律和结合律
    // 影响不大，时间n+m 空间1，上面那个解法也是
    // 不过异或操作运行的比较快，所以还是有提升的
    char findTheDifference(string s, string t) {
        char ans = 0;
        for(auto c: s) ans ^= c;
        for(auto c: t) ans ^= c;
        return ans;
    }
};