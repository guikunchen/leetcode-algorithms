// https://leetcode-cn.com/problems/lexicographical-numbers/
/*给定一个整数 n, 返回从 1 到 n 的字典顺序。

例如，

给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。

请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。 */
class Solution {
public:
	vector<int> ans;
    vector<int> lexicalOrder(int n) {
    	for(int i = 1; i <= 9; i++) {
    		dfs(i, n);
    	}
    	return ans;
    }

    void dfs(int cur, int n) {
    	if(cur > n) return;
    	ans.push_back(i);
    	for(int i = 0; i <= 9; i++) {
    		dfs(cur * 10 + i, n);
    	}
    }
};