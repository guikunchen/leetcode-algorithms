#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
/**
给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
示例：
输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
提示：
0 <= n <= 8  */
class Solution {
public:
	vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> allTrees;
        if(start > end){
        	allTrees.push_back(nullptr);
        	return allTrees;
        }

        for (int i = start; i <= end; ++i)// 选取一个作为根节点
        {
        	// vector<TreeNode*> leftTrees = generateTrees(1, i - 1);// 错的，要考虑右子树
        	vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
        	vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

        	for(TreeNode* l: leftTrees)
	        	for(TreeNode* r: rightTrees){// 乘法原理
	        		TreeNode* cur = new TreeNode(i);
	        		cur->left = l;
	        		cur->right = r;
	        		allTrees.push_back(cur);
	        	}
        }
        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0) return vector<TreeNode*>();
        return generateTrees(1, n);
    }
};