// https://leetcode-cn.com/problems/single-number/ 260题

class Solution {
public:
	// 常规操作
    int singleNumber(vector<int>& nums) {
    	unordered_map<int, int> ht;
    	for(int n : nums){
    		if(ht.find(n) != ht.end()){
    			ht.erase(n);// 节省空间，O(1)
    		}
    		else{
    			ht[n] = 1;
    		}
    	}
    	return ht.begin()->first;
    }

    // 骚操作，用异或，因为异或满足交换律和结合律
    int singleNumber(vector<int>& nums){
    	int ans = 0;
    	for(int n : nums){
    		ans ^= n;
    	}
    	return ans;
    }
};