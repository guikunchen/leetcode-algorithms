#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/encode-and-decode-strings
/*请你设计一个算法，可以将一个 字符串列表 编码成为一个 字符串。
这个编码后的字符串是可以通过网络进行高效传送的，并且可以在接收端被解码回原来的字符串列表。

注意：
因为字符串可能会包含 256 个合法 ascii 字符中的任何字符，所以您的算法必须要能够处理任何可能会出现的字符。
请勿使用 “类成员”、“全局变量” 或 “静态变量” 来存储这些状态，您的编码和解码算法应该是非状态依赖的。
请不要依赖任何方法库，例如 eval 又或者是 serialize 之类的方法。本题的宗旨是需要您自己实现 “编码” 和 “解码” 算法。
*/
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {// 转成长度 + 字符串，长度用四位十六进制表示
        string ans;
        for(auto& s : strs)
            ans += numToHexIntStr(s.size())+s;
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int n;
        for(int i = 0; i < s.size(); i += 4+n)
        {
            n = stoi(s.substr(i,4),0,16);//16进制转成10进制
            ans.emplace_back(s.substr(i+4,n));
        }
        return ans;
    }

    string numToHexIntStr(int n)
    {
        char ch[16];
        sprintf(ch, "%x", n); // x 16进制，d 10进制， o 8进制
        string ans = ch;
        while(ans.size() < 4)
            ans = '0'+ans;
        return ans;
    }
};