#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/nested-list-weight-sum-ii/ 第一题339
/*给一个嵌套整数序列，请你返回每个数字在序列中的加权和，它们的权重由它们的深度决定。

序列中的每一个元素要么是一个整数，要么是一个序列（这个序列中的每个元素也同样是整数或序列）。

与 前一个问题 不同的是，前一题的权重按照从根到叶逐一增加，而本题的权重从叶到根逐一增加。

也就是说，在本题中，叶子的权重为1，而根拥有最大的权重。

示例 1:
输入: [[1,1],2,[1,1]]
输出: 8 
解释: 四个 1 在深度为 1 的位置， 一个 2 在深度为 2 的位置。

示例 2:
输入: [1,[4,[6]]]
输出: 17 
解释: 一个 1 在深度为 3 的位置， 一个 4 在深度为 2 的位置，
一个 6 在深度为 1 的位置。 1*3 + 4*2 + 6*1 = 17。*/

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
    	int presum = 0, ans = 0, i;
    	vector<NestedInteger> nextLevel;
    	for(i = 0; i < nestedList.size(); ++i)
    	{
    		if(nestedList[i].isInteger())
    			presum += nestedList[i].getInteger();
    		else
    		{
                auto temp = nestedList[i].getList();
                for(auto& t : temp)
                    nextLevel.push_back(t);
            }
    		if(i == nestedList.size()-1)
    		{
    			ans += presum;
    			swap(nestedList,nextLevel);
                nextLevel.clear();
                i = -1;
                // 这里presum没有清空，外层的值会在计算内层时加一倍，达到题目要的效果
    		}
    	}
    	return ans;
    }
};