#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/russian-doll-envelopes/
// 就是二维的 最长递增子序列，可以看一下300题

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0)   return 0;
        sort(envelopes.begin(),envelopes.end());// 按width排序
        int res = 1;
        vector<int> dp(envelopes.size() , 1);
        for(int i = 0; i < envelopes.size() ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    res = max(res,dp[i]);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    //优化：动态规划+二分法，时间复杂度O(nlogn)，空间复杂度O(n)
    // 这个不叫dp，这个应该是贪心算法，跟300题那个数组的意思是一样的
    int maxEnvelopes(vector<vector<int>>& envelopes){
        if(envelopes.empty())return 0;
      //先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(),[](const auto& a,const auto& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        vector<int> dp;
        for(auto& en:envelopes){
            int idx=lower_bound(dp.begin(),dp.end(),en[1])-dp.begin();
            if(idx>=dp.size()){
                dp.emplace_back(en[1]);
            }
            else{
                dp[idx]=en[1];
            }
        }
        return dp.size();
    }
};