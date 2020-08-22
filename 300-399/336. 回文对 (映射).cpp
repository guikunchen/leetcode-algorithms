#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/palindrome-pairs/

// 可以用字典树也可以用哈希表来加快查询

class Solution {// 基于哈希表
private:
    vector<string> wordsRev;
    unordered_map<string_view, int> indices;// string_view 是C++17所提供的用于处理只读字符串的轻量对象。这里后缀 view 的意思是只读的视图。

public:
    int findWord(const string_view& s, int left, int right) {
        auto iter = indices.find(s.substr(left, right - left + 1));
        return iter == indices.end() ? -1 : iter->second;
    }

    bool isPalindrome(const string_view& s, int left, int right) {
        int len = right - left + 1;
        for (int i = 0; i < len / 2; i++) {
            if (s[left + i] != s[right - i]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        for (const string& word: words) {
            wordsRev.push_back(word);
            reverse(wordsRev.back().begin(), wordsRev.back().end());
        }
        for (int i = 0; i < n; ++i) {
            indices.emplace(wordsRev[i], i);
        }

        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            int m = words[i].size();
            if (!m) {
                continue;
            }
            string_view wordView(words[i]);
            for (int j = 0; j <= m; j++) {
                if (isPalindrome(wordView, j, m - 1)) {// 右边一部分是回文，那需要找一个单词把右边这部分夹在中间
                    int left_id = findWord(wordView, 0, j - 1);
                    if (left_id != -1 && left_id != i) {
                        ret.push_back({i, left_id});
                    }
                }
                if (j && isPalindrome(wordView, 0, j - 1)) {// 左边一部分是回文，那需要找一个单词把左边这部分夹在中间
                    int right_id = findWord(wordView, j, m - 1);
                    if (right_id != -1 && right_id != i) {
                        ret.push_back({right_id, i});
                    }
                }
            }
        }
        return ret;
    }
};