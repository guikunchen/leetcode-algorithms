#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/minimum-height-trees/

class Solution {
public:
	// 首先，这道题是无向图，不是有向图，需要注意
	// 第一种思路，拓扑排序的变形，一直删度为1的点(叶子节点，而且要同时删)，直至剩下<=2个节点
	// 不严谨证明：最后解只有一个或两个，因该图可以进行等效剪枝（去掉距离相同或者更短的枝干），
	// 最终可以将图化简为一条链，链长度为偶数则有两个解，链长度为奇数则有一个解。
	// BFS，每次去除一层叶子节点，这样保证最后的节点就是我们所要的。
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    	if(n == 1) return {0};// 这种情况没有边，会导致返回空集，实际应该返回0
    	vector<int> degrees(n, 0);
    	vector<vector<int>> adjacency(n);
    	queue<int> oneDegreeQue;

    	for(auto edge : edges){
    		degrees[edge[0]]++;
    		degrees[edge[1]]++;
    		adjacency[edge[0]].push_back(edge[1]);
    		adjacency[edge[1]].push_back(edge[0]);
    	}

    	for(int i = 0; i < n; i++){
    		if(degrees[i] == 1){
    			oneDegreeQue.push(i);
    		}
    	}

    	int cut = oneDegreeQue.size();
    	while(n > 2){
    		n -= cut;
    		for(int i = 0; i < cut; i++){
    			int vertex = oneDegreeQue.front();
    			oneDegreeQue.pop();
    			degrees[vertex]--;
    			for(int node : adjacency[vertex]){
    				if(--degrees[node] == 1){
    					oneDegreeQue.push(node);
    				}
    			}
	    	}
	    	cut = oneDegreeQue.size();
    	}

    	vector<int> ans;
    	while(!oneDegreeQue.empty()){
    		ans.push_back(oneDegreeQue.front());
    		oneDegreeQue.pop();
    	}
    	return ans;
    }

};