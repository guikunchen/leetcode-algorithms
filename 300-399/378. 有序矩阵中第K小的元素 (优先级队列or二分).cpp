// https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        struct point {
            int val, x, y;
            point(int val, int x, int y) : val(val), x(x), y(y) {}
            bool operator> (const point& a) const { return this->val > a.val; }
        };
        // 维护一个大小为n的最小堆，删除k-1个元素后，剩下的最小元素就是第k个最小元素
        priority_queue<point, vector<point>, greater<point>> que;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            que.emplace(matrix[i][0], i, 0);
        }
        for (int i = 0; i < k - 1; i++) {
            point now = que.top();
            que.pop();
            if (now.y != n - 1) {
                que.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
            }
        }
        return que.top().val;
    }
};

class Solution {// 二分，猜mid的值，统计小于等于mid的个数是否大于等于k
   public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1;
        int j = 0;
        int num = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                num += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};