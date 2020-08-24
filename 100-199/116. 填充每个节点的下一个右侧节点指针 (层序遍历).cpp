#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
// 给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
class Solution {
public:
	// 层序遍历进行连接
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> q({root});
        while(!empty(q)){
            Node* tmp = new Node(-1);
            int len = q.size();
            for(int i = 0; i < len; i++) {
                tmp = tmp->next = q.front(); q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        return root;
    }
};