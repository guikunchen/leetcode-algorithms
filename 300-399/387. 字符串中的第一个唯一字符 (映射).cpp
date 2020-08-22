// https://leetcode-cn.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alphabet(26, -1);
        for(int i = 0; i < s.size(); i++){
            if(alphabet[s[i] - 'a'] == -1){
                alphabet[s[i] - 'a'] = i;
            }
            else if(alphabet[s[i] - 'a'] != -1){
                alphabet[s[i] - 'a'] = -2;
            }
        }// 未出现时为-1，出现一次为索引，出现大于一次为-2
        sort(begin(alphabet), end(alphabet));
        for(int i = 0; i < 26; i++){
            if(alphabet[i] >= 0){
                return alphabet[i];
            }
        }
        return -1;
    }

    // 可以用一个hashmap存放每个字母出现的次数。
    // 再从头遍历字符串检查字符的出现次数，如果刚好等于1就返回。
};