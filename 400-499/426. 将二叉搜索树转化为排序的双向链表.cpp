// https://leetcode-cn.com/problems/partition-equal-subset-sum/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return root;
        stack<Node*> stk;
        Node *cur, *head = NULL, *prev = NULL;
        while(root || !stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            cur = stk.top();
            stk.pop();
            if(!head)
                head = cur;//头结点
            root = cur->right;
            cur->left = prev;//当前节点的前驱
            if(prev)
                prev->right = cur;//前面节点的后驱
            prev = cur;//前节点更新
        }
        cur->right = head;//最后的尾节点后继是头
        head->left = cur;//头节点的前驱是尾节点
        return head;//返回头
    }
};