// https://leetcode-cn.com/problems/delete-node-in-a-bst/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
        if (root->val == key) {
            // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
            // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
            if (root->left == NULL) return root->right; 
            // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
            else if (root->right == NULL) return root->left; 
            // 第五种情况：左右孩子节点都不为空，则将删除节点的左孩子放到删除节点的右孩子的最左面节点的左孩子的位置
            // 返回删除节点右孩子为新的根节点。
            else {  
                TreeNode* cur = root->right;
                while(cur->left != NULL) {
                    cur = cur->left;
                }
                cur->left = root->left;
                root = root->right;
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};