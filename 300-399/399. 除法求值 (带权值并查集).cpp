#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/evaluate-division/

class UnionFind {// 用到带权值的并查集，且这个并查集不可以优化
public:
    UnionFind(int size) {
        for (int i = 0; i < size; ++i) {
            parent.push_back(i);
            weight.push_back(1);
        }
    }

    int find(int i) {
        while(i != parent[i]){// 不可以优化
            i = parent[i];
        }
        return i;
    }

    void unite(int x, int y, double val) {// x作为根节点，把y嫁接到x上
        int rooty = find(y);
        if(rooty == y){// y就是根节点
            parent[y] = x;
            weight[y] = val;// x / y = val
        }
        else{// y 不是根节点
            parent[x] = parent[y];
            weight[x] = weight[y] / val;// 把x放在y和y的父节点中间。
            parent[y] = x;
            weight[y] = val;// x / y = val
        }
    }

    double getValueToRoot(int index){
        double ans = 1.0;
        while(index != parent[index]){
            ans *= weight[index];
            index = parent[index];
        }
        return ans;
    }

    void print(){
        for(auto n : parent){
            cout<< n << " ";
        }
        cout<< endl;
        for(auto n : weight){
            cout<< n << " ";
        }
        cout<< endl;
    }

private:
    vector<int> parent;
    vector<double> weight;// 权值
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> hashmap;
        int index = 0;
        for(auto v : equations){
            for(auto str : v){
                if(hashmap.count(str) == 0){
                    hashmap[str] = index;
                    index++;
                }
            }
        }
        UnionFind uf(index);

        for(int i = 0; i < equations.size(); i++){
            uf.unite(hashmap[equations[i][0]], hashmap[equations[i][1]], values[i]);
        }

        uf.print();
        for(auto p : hashmap){
            cout<<"key: "<<p.first<<" second: "<<p.second<<endl;
        }

        vector<double> ans;
        for(int i = 0; i < queries.size(); i++){
            if(hashmap.count(queries[i][0]) == 0 || hashmap.count(queries[i][1]) == 0
                || uf.find(hashmap[queries[i][1]]) != uf.find(hashmap[queries[i][0]])){
                ans.push_back(-1.0);
            }
            else{
                ans.push_back(uf.getValueToRoot(hashmap[queries[i][1]]) / uf.getValueToRoot(hashmap[queries[i][0]]));
            }
        }
        return ans;
    }
};