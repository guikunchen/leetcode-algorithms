// https://leetcode-cn.com/problems/the-skyline-problem/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> all;
        vector<vector<int>> res;
        
        for (auto& e : buildings) {
            all.insert(make_pair(e[0], -e[2])); // critical point, left corner
            all.insert(make_pair(e[1], e[2])); // critical point, right corner
        }
        
        multiset<int> heights({0}); // 保存当前位置所有高度。   
        vector<int> last = {0, 0}; // 保存上一个位置的横坐标以及高度； 将heights塞入一个0，0代表着没有建筑，它既不能被删除，同时还能再没有建筑的时候在res里补值。
        for (auto& p : all) {
            if (p.second < 0) heights.insert(-p.second); // 左端点，高度入堆
            else heights.erase(heights.find(p.second)); // 右端点，移除高度
            
            // 当前关键点，最大高度
            auto maxHeight = *heights.rbegin();// multiset自动排序，rbegin()指向最大元素
            
            // 当前最大高度如果不同于上一个高度，说明这是一个转折点
            if (last[1] != maxHeight) {
                // 更新 last，并加入结果集
                last[0] = p.first;
                last[1] = maxHeight;
                res.push_back(last);
            }
        }
        return res;
    }
};
/*
很巧妙的做法，利用了 muliset 这一数据结构自动排序的特性。

multiset中的元素是 pair，对pair排序默认的方式是，先比较 first，哪个小则排在前；first 相等则 second小的排在前。 而 first 这里表示横坐标，second 为负时，表示建筑的左侧在这一位置，其绝对值表示建筑在的高度；second 为正时，表示建筑的右侧在这一位置。

所以对muliset遍历时，首先会取出横坐标小的点。如果2个点横坐标相等，会先取出 second 小的点，对于负数来说，其实就是高度更高的建筑。也就是说，两个点上有高度不同的建筑，会先取高的出来放入高度集合，集合中高度最大值和之前高度不同，就直接放入结果。后面更低高度的建筑加入并不会改变最大高度。

如果second为正，表示建筑物在此处结束，需要把相应高度从高度集合中删除。有相同建筑同时在此结束，则会先让较低的建筑离开，因为它们不会改变最大高度。只有当最高的建筑物离开时，才进行改变。

如果一个位置既有建筑物进来，又有建筑物离开，会先选择进来的，同理。 总结起来，我就是想说，这里把建筑物起始点的高度设为负数，真的很巧妙。
*/