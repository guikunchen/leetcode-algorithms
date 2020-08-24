#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/unique-binary-search-trees/


class Solution {
public:
	// 动态规划
	// G(n) = \sum(i = 1 ~ n) f(i)
	// f(i) = G(i - 1) * G(n - i)
	// G(n) = \sum(i = 1 ~ n) G(i - 1) * G(n - i)
    int numTrees(int n) {
    	vector<int> G(n + 1, 0);
        //int *G = new int[n + 1]{0};
        G[0] = 1;
        G[1] = 1;
        for(int i = 2; i <= n; i++){
        	for(int j = 1; j <= i; j++){
        		G[i] += G[j - 1] * G [i - j];
        	}
        }
        return G[n];
    }

    // 卡特兰数有个计算公式G(n+1) = ( 2(2n + 1)(Gn) ) / (n + 2)
    int numTrees(int n) {
    	unsigned long long C = 1;// 防止溢出
    	for(int i = 1; i < n; i++) {
            C = C << 1;// 要先左移，不能除完再左移
    		C = (2 * i + 1) * C / (i + 2);
    	}
        return int(C);
    }
};