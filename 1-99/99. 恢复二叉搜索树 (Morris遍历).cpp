#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/recover-binary-search-tree/

// 方法一：先中序遍历把结果存起来，然后找出两个需要交换的值，再遍历一次树交换值

// 方法二：迭代中序遍历，记录需要交换的节点（而不是值），然后直接交换

class Solution {
  void swap(TreeNode a, TreeNode b) {
    int tmp = a.val;
    a.val = b.val;
    b.val = tmp;
  }

  void recoverTree(TreeNode root) {
    Deque<TreeNode> stack = new ArrayDeque();
    TreeNode x = null, y = null, pred = null;

    while (!stack.isEmpty() || root != null) {
      while (root != null) {
        stack.add(root);
        root = root.left;
      }
      root = stack.removeLast();
      if (pred != null && root.val < pred.val) {
        y = root;
        if (x == null) x = pred;
        else break;
      }
      pred = root;
      root = root.right;
    }

    swap(x, y);
  }
}

// 方法三：把方法二的迭代改成递归
// 使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？
// 方法四：莫里斯Morris遍历，类似于线索二叉树，把前驱节点的右指针指向自己。
// 利用叶子结点的右指针指向下一个结点！

class Solution {
public:
    void swap(TreeNode* x, TreeNode *y) {
        if(x == nullptr || y == nullptr) return;
        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
    void recoverTree(TreeNode* root) {
    // predecessor is a Morris predecessor. 
    // In the 'loop' cases it could be equal to the node itself predecessor == root.
    // pred is a 'true' predecessor, 
    // the previous node in the inorder traversal.
        TreeNode *x = nullptr, *y = nullptr, *pred = nullptr;

        while(root != nullptr) {
        // If there is a left child
        // then compute the predecessor.
        // If there is no link predecessor.right = root --> set it.
        // If there is a link predecessor.right = root --> break it.
            if(root->left != nullptr) {
                // Predecessor node is one step left 
                // and then right till you can.
                TreeNode *predecessor = root->left;
                while(predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                // set link predecessor.right = root
                // and go to explore left subtree
                if(predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    if(pred != nullptr && root->val < pred->val) {// check for the swapped nodes
                        y = root;
                        if(x == nullptr) x = pred;
                    }
                    predecessor->right = nullptr;// break link predecessor.right = root 
                    pred = root;
                    root = root->right;// link is broken : time to change subtree and go right
                }
            } else {// If there is no left child then just go right.
                if(pred != nullptr && root->val < pred->val) {// check for the swapped nodes
                    y = root;
                    if(x == nullptr) x = pred;
                }
                pred = root;
                root = root->right;
            }
        } 
        swap(x, y);
    }
};