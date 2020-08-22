#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/rearrange-string-k-distance-apart
/*给你一个非空的字符串 s 和一个整数 k，你要将这个字符串中的字母进行重新排列，使得重排后的字符串中相同字母的位置间隔距离至少为 k。

所有输入的字符串都由小写字母组成，如果找不到距离至少为 k 的重排结果，请返回一个空字符串 “”。

示例 1：
输入: s = "aabbcc", k = 3
输出: "abcabc" 
解释: 相同的字母在新的字符串中间隔至少 3 个单位距离。

示例 2:
输入: s = "aaabc", k = 3
输出: "" 
解释: 没有办法找到可能的重排结果。

示例 3
输入: s = "aaadbbcc", k = 2
输出: "abacabcd"
解释: 相同的字母在新的字符串中间隔至少 2 个单位距离。*/

/*先对字符计数
将 <字符,计数> 插入优先队列（数量优先，字符顺序其次）
队列的 size >= k 时，取出前 k 大的加入 ans 字符串，相应字符计数 -1，将计数不为0的再次放回队列
当队列 size < k 时，队列内的计数都只能为 1， 不然多出来的字符间隔不能 满足 k 的要求*/

class Solution {
    struct cmp
    {
        bool operator()(pair<char, int>& a, pair<char, int>& b){
            if(a.second == b.second)
                return a.first < b.first;// 数量相同按字典序
            return a.second < b.second;//数量多的优先
        }
    };
public:
    string rearrangeString(string s, int k) {
        if(k <= 1) return s;
        unordered_map<char, int> count;
        for(int i = 0; i < s.size(); i++) 
            count[s[i]]++;//计数
        priority_queue<pair<char, int>, vector<pair<char,int>>, cmp> q;
        for(auto& c : count)
            q.push(c);//插入优先队列

        string ans;
        while(q.size() >= k) {
            vector<pair<char, int>> temp;
            int t = k;
            while(t--) {//拿出前k个最多的
                auto tp = q.top();
                q.pop();
                int num = tp.second;
                char ch = tp.first;
                ans += ch;
                num--;
                if(num != 0)//剩余个数不为0的，记录起来待会一起放回队列
                    temp.push_back({ch, num});
            }
            for(auto& char_num : temp)// 一起放回队列
                q.push(char_num);
        }
        while(!q.empty()) {
            if(q.top().second == 1) {
                ans += q.top().first;
                q.pop();
            }
            else//计数不为1的，间距不满足要求
                return "";
        }
        return ans;
    }
};