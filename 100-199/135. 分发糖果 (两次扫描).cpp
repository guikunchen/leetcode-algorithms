#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/candy/

class Solution {
public:
    // 方法二，使用两个数组，再取max合并起来
    int candy(vector<int>& ratings) {
        int sum = 0;
        vector<int> left2right(ratings.length, 1);
        vector<int> right2left(ratings.length, 1);

        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left2right[i] = left2right[i - 1] + 1;
            }
        }
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2left[i] = right2left[i + 1] + 1;
            }
        }
        for (int i = 0; i < ratings.length; i++) {
            sum += max(left2right[i], right2left[i]);
        }
        return sum;
    }

    // 方法三，在方法二的基础上优化，仅使用一个数组
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.length, 1);

        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        int sum = candies[ratings.length - 1];
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }

        return sum;
    }

    // 方法四，用波峰波谷，条件太多懒得看了
};