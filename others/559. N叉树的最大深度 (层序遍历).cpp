#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;

        queue<Node*> q;
        q.push(root);
        int left = 1;
        int depth = 0;
        while(!q.empty()){
            Node* node = q.front(); q.pop();
            for(int i = 0; i < node->children.size(); i++){
                q.push(node->children[i]);
            }
            if(--left == 0){
                left = q.size();
                depth++;
            }
        }
        return depth;
    }
};