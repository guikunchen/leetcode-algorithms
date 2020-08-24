#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/zigzag-iterator
/*这一题其实没有什么很取巧的东西。就是两个数组来回跳就完事了，与其说是复杂还不如说是要小心处理。
但是follow up 是要你兼容K个数组，其实也是差不多的，把K个数组放进一个ArrayList里面当成是一个2d数组就好了。
然后就是保持两个cursors，一个是对行的，另一个是对列的。
对行的cursor不停往下走，走到最下面那个array之后对列的cursor的往前走一步。
在这个过程里，如果某个数组的长度小于关于列的cursor，就直接删掉。
*/
class ZigzagIterator {
    vector<vector<int>> data;
    int row = 0;
    int col = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size() != 0) {
            data.push_back(v1);
        }
        if(v2.size() != 0) {
            data.push_back(v2);
        }
    }

    int next() {
        int result = data[row][col];
        if(col == data[row].size() - 1) {
            data.erase(&data[row]);// 访问到最后一个，删除改行
        } else {
            row = (row + 1) % data.size();// 从上到下循环遍历
        }
        return result;
    }

    bool hasNext() {
        return !data.empty();
    }
};