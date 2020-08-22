#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/inorder-successor-in-bst-ii/
/*给定一棵二叉搜索树和其中的一个节点 node ，找到该节点在树中的中序后继。
如果节点没有中序后继，请返回 null 。
一个结点 node 的中序后继是键值比 node.val大所有的结点中键值最小的那个。
你可以直接访问结点，但无法直接访问树。
每个节点都会有其父节点的引用。节点定义如下：
*/
// 如果有右子树，右子树的最左边就是下一个节点。
// 如果没有，且该节点是父节点的左孩子，那答案就是父节点，如果是父节点的右孩子，那一直往上找，找到第一个节点的连接左孩子，就是答案。
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(!node->right) {// 没有右节点,那就查上面的多层祖父节点
            int v = node->val;
            while(node->parent && node->parent->val < v)
            {
                node = node->parent;
            }
            return node->parent;
        }
        // 右节点的最左边
        Node* cur = node->right, *prev = NULL;
        while(cur) {
            prev = cur;
            cur = cur->left;
        }
        return prev;
    }
};
class Solution {// 不访问节点值
public:
    Node* inorderSuccessor(Node* node) {
        if(!node->right) {// 没有右节点,那就查上面的多层祖父节点
            while(node->parent && node->parent->left != node) {                   
                node = node->parent;//当遇到父节点的左节点是 当前node时 即找到
            }
            return node->parent;
        }
        // 右节点的最左边
        Node* cur = node->right, *prev = NULL;
        while(cur) {
            prev = cur;
            cur = cur->left;
        }
        return prev;
    }
};