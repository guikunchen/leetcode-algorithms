#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/course-schedule-ii/


class Solution {
public:
	// 入度表BFS法/DFS法。考察拓扑排序。给定的图必须为有向无环图（DAG）
	// 获取邻接矩阵，生成入度表，借助队列queue存储入度为0的节点。
	// 每次出队，都要把这个节点的所有邻接节点的入度-1，且numcourese也要-1。
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses, 0);
        vector<vector<int>> adjacency(numCourses);
        queue<int> que;
        vector<int> sequence;

        for(auto v : prerequisites){
            inDegrees[v[0]]++;
            adjacency[v[1]].push_back(v[0]);// 学习v[0]之前要先学习v[1]
        }

        for(int i = 0; i < numCourses; i++){
            if(inDegrees[i] == 0){
                que.push(i);
            }
        }

        while(!que.empty()){
            int index = que.front(); que.pop();
            numCourses--;
            sequence.push_back(index);
            for(int n : adjacency[index]){
                if(--inDegrees[n] == 0){
                    que.push(n);
                }
            }
        }
        return numCourses == 0 ? sequence : vector<int>();
    }

    // 也可以用栈记录DFS的结果，最后出栈序列就是拓扑排序
    // 比如拓扑排序12345，那么1就是最后入栈的，也就是说先深度遍历完再进行入栈操作。
    // 如果一个节点被访问两次代表有环，就返回空
};