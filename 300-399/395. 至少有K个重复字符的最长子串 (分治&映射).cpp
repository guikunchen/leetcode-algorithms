// https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/

class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> umap;
        for (auto c : s) umap[c]++;
        vector<int> split;
        for (int i = 0; i < s.size(); i++) {// 分治，次数太少的字符把各个区间隔开
            if (umap[s[i]] < k) split.push_back(i);
        }

        if (split.size() == 0) return s.length();// 每个字符的出现次数都大于k

        int ans = 0, left= 0;
        split.push_back(s.length());
        for (int i = 0; i < split.size(); i++) {
            int len = split[i] - left;
            if (len > ans) {// 如果这个区间的长度小于等于ans，就没必要取判断了
                ans = max(ans, longestSubstring(s.substr(left, len), k));
            }
            left = split[i]+1;
        }
        return ans;
    }
};