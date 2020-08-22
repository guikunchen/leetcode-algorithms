#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/water-and-jug-problem/
/*有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？

如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

你允许：

装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空
示例 1: (From the famous "Die Hard" example)

输入: x = 3, y = 5, z = 4
输出: True
示例 2:

输入: x = 2, y = 6, z = 5
输出: False*/

using PII = pair<int, int>;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        stack<PII> stk;
        stk.emplace(0, 0);
        // 使用一个哈希集合（HashSet）存储所有已经搜索过的 remain_x, remain_y 状态，保证每个状态至多只被搜索一次。
        // 防止陷入死循环
        auto hash_function = [](const PII& o) {return hash<int>()(o.first) ^ hash<int>()(o.second);};
        unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
        while (!stk.empty()) {
            if (seen.count(stk.top())) {
                stk.pop();
                continue;
            }
            seen.emplace(stk.top());
            
            auto [remain_x, remain_y] = stk.top();
            stk.pop();
            if (remain_x == z || remain_y == z || remain_x + remain_y == z) {
                return true;
            }
            stk.emplace(x, remain_y);// 把 X 壶灌满。
            stk.emplace(remain_x, y);// 把 Y 壶灌满。
            stk.emplace(0, remain_y);// 把 X 壶倒空。
            stk.emplace(remain_x, 0);// 把 Y 壶倒空。
            // 把 X 壶的水灌进 Y 壶，直至灌满或倒空。
            stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
            // 把 Y 壶的水灌进 X 壶，直至灌满或倒空。
            stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
        }
        return false;
    }
};

/*而只要满足 z≤x+y，且这样的 a, b 存在，那么我们的目标就是可以达成的。这是因为：
若 a≥0,b≥0，那么显然可以达成目标。
若 a<0，那么可以进行以下操作：
1.往 y 壶倒水；
2.把 y 壶的水倒入 x 壶；
3.如果 y 壶不为空，那么 x 壶肯定是满的，把 x 壶倒空，然后再把 y 壶的水倒入 x 壶。
重复以上操作直至某一步时 x 壶进行了 a 次倒空操作，y 壶进行了 b 次倒水操作。
若 b<0，方法同上，x 与 y 互换。
而贝祖定理告诉我们，ax+by=z 有解当且仅当 z 是 x,y 的最大公约数的倍数。
因此我们只需要找到 x, y的最大公约数并判断 z 是否是它的倍数即可。*/
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        return z % gcd(x, y) == 0;
    }
};