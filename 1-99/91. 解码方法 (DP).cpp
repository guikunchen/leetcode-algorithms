#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/decode-ways/
/*一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。 */
class Solution {
public:
    int numDecodings(string s) {
	    if (s[0] == '0') return 0;
	    // 只依赖于前两个，用临时变量存一下就好了
	    int pre = 1, curr = 1;// dp[-1] = dp[0] = 1
	    for (int i = 1; i < s.size(); i++) {
	        int tmp = curr;
	        if (s[i] == '0')
	            if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre;// 两个字符合在一起
	            else return 0;// 不合法
	        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
	            curr = curr + pre;// 可以解码成两种
	        pre = tmp;// 若s[i - 1] == '0' && s[i] >= '3'，curr不变，pre = curr（已经存在tmp里）
	    }
	    return curr;
	}
};