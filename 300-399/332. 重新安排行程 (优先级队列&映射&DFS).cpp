#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/reconstruct-itinerary/

class Solution {
public:
	// 实际上求的是欧拉路径，即给定一个有向连通图，指定一个顶点开始，
	// 不重复（边，不是顶点）地遍历所有顶点。 题目要求的是按字典排序的欧拉路径

	// Hierholzer算法：从合理的起始点进行DFS，就是一条欧拉路径
	// DFS又有递归和非递归两种解法
	vector<string> findItinerary(vector<vector<string>>& tickets) {// 非递归
    	vector<string> ans;
    	if(tickets.size() == 0) return ans;
    	// 用优先级队列(用堆实现)来实现字典序排列
    	unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adjacency;
    	
    	for(auto ticket : tickets){
    		adjacency[ticket[0]].push(ticket[1]);
    	}

    	stack<string> st;
    	st.push("JFK");
    	while(!st.empty()){
    		priority_queue<string, vector<string>, greater<string>> *que = &adjacency[st.top()];
    		while(!que->empty()){
				string dest = que->top(); que->pop();// 断掉边
				st.push(dest);
				que = &adjacency[dest];// 深度遍历，切换到下一个节点的邻接表
			}
			ans.push_back(st.top()); st.pop();
    	}

    	reverse(ans.begin(), ans.end());
    	return ans;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
    	vector<string> ans;
    	if(tickets.size() == 0) return ans;
    	unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adjacency;
    	
    	for(auto ticket : tickets){
    		adjacency[ticket[0]].push(ticket[1]);
    	}
    	visit(adjacency, "JFK", ans);
    	reverse(ans.begin(), ans.end());
    	return ans;
    }

    void visit(unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &adjacency,
    	string vertex,
    	vector<string> &ans){
    	priority_queue<string, vector<string>, greater<string>> *que = &adjacency[vertex];
	    while(!que->empty()){
			string dest = que->top(); que->pop();
			visit(adjacency, dest, ans);
		}
    	ans.push_back(vertex);
    }
};

{{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}}
{{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}}