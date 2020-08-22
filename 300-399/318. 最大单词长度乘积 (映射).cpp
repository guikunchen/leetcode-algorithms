#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/maximum-product-of-word-lengths/
/*给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，
并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        map<int, int> bitHash;
        int bitMask = 0, res = 0;
        for(auto str : words)
        {
            bitMask = 0;
            for(auto ch : str)
            {
                bitMask |= 1 << ch-'a';
            }
            bitHash[bitMask] = max(bitHash[bitMask], (int)str.size());
        }

        for(auto it = bitHash.begin(); it != bitHash.end(); ++it)
        {
            auto iter = ++it;
            --it;
            for(; iter != bitHash.end(); ++iter){
                if(!(it->first & iter->first))
                    res = max(res, it->second * iter->second);
            }
        }
        return res;
    }
};