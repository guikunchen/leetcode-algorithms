#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/flatten-2d-vector
/*请设计并实现一个能够展开二维向量的迭代器。该迭代器需要支持 next 和 hasNext 两种操作。、
示例：
Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

iterator.next(); // 返回 1
iterator.next(); // 返回 2
iterator.next(); // 返回 3
iterator.hasNext(); // 返回 true
iterator.hasNext(); // 返回 true
iterator.next(); // 返回 4
iterator.hasNext(); // 返回 false
*/
class Vector2D {
	vector<vector<int>> arr;
	int row = 0, col = 0, m;
public:
    Vector2D(vector<vector<int>>& v) {
    	arr = v;
        m = arr.size();
    }
    
    int next() {
    	// 题目假定 next() 的调用总是合法的，所以少一个判断条件
        while(col == arr[row].size()) {// 跳过没有剩余元素的行
    		row++;
    		col = 0;
    	}
    	return arr[row][col++];
    }
    
    bool hasNext() {
        while(row < m && col == arr[row].size()) {// 跳过没有剩余元素的行
    		row++;
    		col = 0;
    	}
    	// 索引合法
    	return row < m-1 || (row == m-1 && col < arr[m-1].size());
    }
};