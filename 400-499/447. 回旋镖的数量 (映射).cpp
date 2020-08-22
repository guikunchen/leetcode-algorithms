// https://leetcode-cn.com/problems/number-of-boomerangs/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i ++){
            unordered_map<int,int> mp;// key距离，value出现的频率
            for(int j = 0; j < points.size(); j ++){
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                mp[ dx * dx + dy * dy ]  ++;
            }
            for(auto x:mp){// 频率只有1的话就是加0，没差
                // 如果超过1，比如6个点和这个点距离相等，那这个点固定放最左边，剩下两个位置有6*5种可能
                ans += x.second * (x.second - 1);
            }
        }
        return ans;
    }
};