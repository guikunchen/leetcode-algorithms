#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/paint-fence
/*有 k 种颜色的涂料和一个包含 n 个栅栏柱的栅栏，每个栅栏柱可以用其中一种颜色进行上色。
你需要给所有栅栏柱上色，并且保证其中相邻的栅栏柱 最多连续两个 颜色相同。然后，返回所有有效涂色的方案数。
注意:
n 和 k 均为非负的整数。
*/
/*递推式:第三根柱子要不和第一根柱子不是一个颜色,要不和第二根柱子不是一个颜色,所以和第一根柱子颜色不一样的概率是k-1乘以第一根柱子的概率

和第二根柱子颜色不一样的概率是k-1乘以第二根柱子的概率,同时如果和第一根柱子颜色相同,则已经包含在与第二根柱子颜色不同里面,反之亦然,所以相加就是总的概率*/
class Solution {
public:
    int numWays(int n, int k) {
    	if(n==0 || k==0)
    		return 0;
    	vector<int> dp(n,0);
    	//dp[i]表示遍历完i栅栏的方案数
    	if(n>=1)
    		dp[0] = k;
    	if(n>=2)
    		dp[1] = k*k;
    	for(int i = 2; i < n; ++i)
    	{
    		dp[i] = dp[i-1]*(k-1)+dp[i-2]*(k-1);
    	}
    	return dp[n-1];
    }
};