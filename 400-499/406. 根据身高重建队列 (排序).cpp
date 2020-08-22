// https://leetcode-cn.com/problems/queue-reconstruction-by-height/
/*
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]*/


/*身高从低到高排序， 然后从矮个开始处理。
对于(h,k)这个人， 从结果队列的前面开始数到第k个， 就是他应该在的位置。
关键是怎么数呢？
如果一个位置是空的， OK，留给比我高的人，计数加1.
如果一个位置上的人和我一样高， OK，计数加1.
如果这个位置上的人比我矮， 对不起，看不见你， pass。
如此数到第k个位置， 就是我应该呆的地方。*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end());  // sort people from shortest to tallest

        vector<vector<int>> res(people.size());
        for(auto & p : people){
            int count = -1; // count the position that is empty or height equals to p[0]
            for(int i = 0; i < res.size(); i++){
                if(res[i].empty() || res[i][0] >= p[0]) count++;
                if(count == p[1]){
                    res[i] = p;
                    break;
                }
            }
        }
        return res;
    }
};