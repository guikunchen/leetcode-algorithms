#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[i][0] == 1) {
                f[j] = 0;
            }
            for (int j = 1; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                f[j] += f[j - 1];
            }
        }

        return f.back();
    }
};