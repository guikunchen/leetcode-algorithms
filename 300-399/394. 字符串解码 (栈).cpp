// https://leetcode-cn.com/problems/decode-string/ 跟150题逆波兰式结合一下

// 数字存放在数字栈，字符串存放在字符串栈，遇到右括号时候弹出一个数字栈，字母栈弹到左括号为止。
class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<int> multiStk;
        stack<string> stringStk;

        int multi = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                multi = multi * 10 + s[i] - '0';
            } else if(s[i] == '[') {
                stringStk.emplace(ans);
                multiStk.emplace(multi);
                ans.clear();
                multi = 0;
            } else if(s[i] == ']') {
                string tmp = stringStk.top(); stringStk.pop();
                int mul = multiStk.top(); multiStk.pop();
                for(int i = 0; i < mul; i++) {
                    tmp += ans;
                }
                ans = tmp;
            } else {
                ans.emplace_back(s[i]);// 累计字符串
            }
        }
        return ans;
    }
};