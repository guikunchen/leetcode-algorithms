#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/largest-number/

// 这道题必须要重写一个比较逻辑，不可以存在逆序对
// 也就是说 19 288 要改为 288 19，因为 19288 < 28819
// 这个比较逻辑就是字符串连接之后，比较字符串对应的整数的大小。
bool cmp(string a, string b){
    return a + b > b + a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int i = 0; i < nums.size(); i++){
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(), v.end(), cmp);
        if(v.front() == "0") return "0";// 第一个字符串是0
        string ans = "";
        for(int i = 0; i < v.size(); i++){
            ans += v[i];
        }
        return ans;
    }
};