// https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int cur = 0;
        for(int i = 0, j = 0; i < n; j = i) {// i会指向下一个字符串，每次滑动窗口ij在同一位置
            while(i < n && chars[i] == chars[j]) {
                i++;
            }
            chars[cur++] = chars[j];
            if(i - j == 1) {
                continue;
            }
            string s = to_string(i - j);
            for(int t = 0; t < s.size(); t++) {
                chars[cur++] = s[t];
            }
        }
        return cur;
    }
};
