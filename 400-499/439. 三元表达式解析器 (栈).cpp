// https://leetcode-cn.com/problems/ternary-expression-parser

/*你可以假定给定的表达式始终都是有效的并且只包含数字 0-9, ?, :, T 和 F (T 和 F 分别表示真和假）。
示例 3：
输入： "T?T?F:5:3"
输出： "F"
解释： 条件表达式自右向左结合。使用括号的话，相当于：

             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 或者       -> "(T ? F : 5)"
          -> "F"                                     -> "F"
*/
class Solution {// 逆序遍历，每次 i - 2 找符号
public:// ： 把后面的数压栈，？把前面的数更新为表达式的值，并弹栈
    string parseTernary(string expression) {
        stack<char> s1;
        for(int i = expression.length() - 1; i >= 2; i -= 2)//找?或者:
        {
            if(expression[i-1] == ':')//前一个是 :
                s1.push(expression[i]);
            else//前一个是 ?
            {
                expression[i-2] = expression[i-2] == 'T' ? expression[i] : s1.top();
                // ? 前面 更新为表达式的值
                s1.pop();
            }
        }
        return string(1,expression[0]);
    }
};