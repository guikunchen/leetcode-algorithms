// https://leetcode-cn.com/problems/random-pick-index/

class Solution {
public:
    Solution(vector<int>& nums) {
        pvec = &nums;
    }
    
    int pick(int target) {
        int count = 0;
        int res = 0;
        for (int i=0;i<(*pvec).size();++i){
            if ((*pvec)[i] == target){
                ++count;
                if (rand() % count == 0) {
                    res = i;
                }
            }
        }
        return res;
    }
private:
    vector<int>* pvec;
};