#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> mp;
    Node* cloneGraph(Node* node) {// 递归dfs
        if(node == nullptr) return node;
        if(mp.count(node) == 1) return mp[node];
        mp[node] = new Node(node->val);
        for(const auto &v : node->neighbors){
            mp[node]->neighbors.push_back(cloneGraph(v));
        }
        return mp[node];
    }

    Node* cloneGraph(Node* node) {// 非递归dfs
        if(node == nullptr) return node;

        unordered_map<Node *, Node *> mp;
        stack<Node *> st;
        st.push(node);
        mp[node] = new Node(node->val);

        while(!st.empty()){
            Node *vertex = st.top(); st.pop();
            
            for(const auto &v : vertex->neighbors){
                if(mp.count(v) == 0){
                    st.push(v);
                    mp[v] = new Node(v->val);
                }
                mp[vertex]->neighbors.push_back(mp[v]);
            }
        }
        return mp[node];
    }

    Node* cloneGraph(Node* node) {// bfs
        if(node == nullptr) return node;

        unordered_map<Node *, Node *> mp;
        queue<Node *> que;
        que.push(node);
        mp[node] = new Node(node->val);

        while(!que.empty()){
            Node *vertex = que.front(); que.pop();
            
            for(const auto &v : vertex->neighbors){
                if(mp.count(v) == 0){
                    que.push(v);
                    mp[v] = new Node(v->val);
                }
                mp[vertex]->neighbors.push_back(mp[v]);
            }
        }
        return mp[node];
    }
};