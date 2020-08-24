#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
		map<int, int> tmp;
		for(int i=0;i<nums.size();i++){
			tmp[nums[i]]=i;
		}
		for(int i=0;i<nums.size();i++){
            int t=target-nums[i];
			if(tmp.count(t)!=0 && tmp[t]!=i){
				ans.push_back(i);
				ans.push_back(tmp[t]);
				return ans;
			}
		}
		return ans;
    }
};

// 用空间换时间