#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;
// https://leetcode-cn.com/problems/score-of-parentheses/
/*给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：

() 得 1 分。
AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
(A) 得 2 * A 分，其中 A 是平衡括号字符串。 */
class Solution {
public:
    // 用一个栈维护每层深度的值，下面给出了字符串 (()(())) 每次对应的栈的情况：
    // [0, 0] (
    // [0, 0, 0] ((
    // [0, 1] (()
    // [0, 1, 0] (()(
    // [0, 1, 0, 0] (()((
    // [0, 1, 1] (()(()
    // [0, 3] (()(())
    // [6] (()(()))
    int scoreOfParentheses(string S) {
        stack<int> s;
        s.push(0);// 栈最下面的元素就是最终的分数
        for(char c: S){
            if(c == '('){
                s.push(0);
            }
            else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b + max(a << 1, 1));
            }
        }
        return s.top();
    }
    // 只有 () 会对字符串 S 贡献实质的分数
    int scoreOfParentheses(string S) {
        int ans = 0, depth = 0;
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '('){
                depth++;
            }
            else{
                depth--;
                if(S[i - 1] == '('){
                    ans += 1 << depth;
                }
            }
        }
        return ans;
    }
};