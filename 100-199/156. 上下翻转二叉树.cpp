#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/binary-tree-upside-down

/* 给定一个二叉树，其中所有的右节点要么是具有兄弟节点（拥有相同父节点的左节点）
的叶节点，要么为空，将此二叉树上下翻转并将它变成一棵树，
原来的右节点将转换成左叶节点。返回新的根。
给定一个二叉树，其中所有的右节点要么是具有兄弟节点（拥有相同父节点的左节点）的叶节点，要么为空
将此二叉树上下翻转并将它变成一棵树， 原来的右节点将转换成左叶节点。返回新的根。

例子:

输入: [1,2,3,4,5]

    1
   / \
  2   3
 / \
4   5

输出: 返回二叉树的根 [4,5,2,#,#,3,1]

   4
  / \
 5   2
    / \
   3   1  
说明:
*/

// 如果存在三个节点，父节点和左右子节点（如果有右节点，至少会有一个左节点），
// 那么新的树的结构是左节点变为父节点，右节点变为新的父节点的左节点，
// 原来的父节点变为现在的右节点；


public TreeNode upsideDownBinaryTree(TreeNode root) {
    if(root == null || (root.left == null && root.right == null)) {
        return root;
    }

    TreeNode leftRoot = upsideDownBinaryTree(root.left);

    // 左子树翻转完后
    // 找到新的子树的最右的子节点，并把当前父节点和右节点连接上去就可以了；
    TreeNode tmpNode = leftRoot;

    while(tmpNode.right != null) {
        tmpNode = tmpNode.right;
    }

    tmpNode.left = root.right;
    tmpNode.right = root;

    root.right = null;
    root.left = null;
    return leftRoot;
}