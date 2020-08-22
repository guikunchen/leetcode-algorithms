#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/flatten-nested-list-iterator/
/*输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
*/

// 以NestedInteger为节点，用栈从尾到头保存也可以
class NestedIterator {// 按序全部存到vector里
private:
  vector<int> v;
  int ind = 0;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto iter = nestedList.begin(); iter != nestedList.end(); iter++) {
      parseData(*iter);
    }
  }
  void parseData(NestedInteger item) {
    if (item.isInteger()) {
      v.push_back(item.getInteger());
    } else {
      auto list = item.getList();
      for (auto iter = list.begin(); iter != list.end(); iter++) {
        parseData(*iter);
      }
    }
  }

  int next() {
    return v[ind++];
  }

  bool hasNext() {
    if (ind >= v.size()) return false;
    return true;
  }
};