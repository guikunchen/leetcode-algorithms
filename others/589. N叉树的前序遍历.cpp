#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/


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
    vector<int> preorder(Node* root) {
    	vector<int> ans;
    	if(root == nullptr) return ans;

        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
        	Node *node = s.top(); s.pop();
        	ans.push_back(node->val);
        	for(int i = node->children.size() - 1; i >= 0; i--){
        		s.push(node->children[i]);
        	}
        }
        return ans;
    }
};