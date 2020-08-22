// https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed
/*注意: 允许出现重复元素。
note1: unordered_map<int, unordered_set<int> > ump; 
保存某个值 和 这个值在 vector 中的下标， 数据结构使用 哈希表
note2: 删除元素时， 该元素与最后一个元素置换， 然后 pop_back; 
容易发生错误的地方是， 删除的元素自身就是 最后一个元素
*/

class RandomizedCollection {
public:
    /** Initialize your data structure here. */

    // 删除功能则相对复杂一点，首先通过hash表O(1)地找到删除目标在vector中的位置，然后为了避免vector删除中间元素时平移后面元素所需的线性耗时，我们在删除操作前将需要删除的元素与vector最后一个元素进行位置交换，此时需要删除的元素处在vector的尾部，删除之即可

    // 这里保存某个值 和 储存这个值的 vector  indices
    unordered_map<int, unordered_set<int> > ump;
    vector<int> recs;

    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        recs.push_back(val);
        bool res = ump.find(val) == ump.end();

        int index = recs.size() - 1;
        ump[val].insert(index);

        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // for(auto c: recs){
        //     cout << c << " ";
        // }

        bool res = ump.find(val) != ump.end() && ump[val].size() > 0; // 存在 val 
        if(!res) return res; // false

        int lastindex = recs.size() - 1;
        int lastVal = recs.back();

        // 从 val 对应的 index 集合总删除 首个元素
        int deleteIndex = *ump[val].begin();
        ump[val].erase(ump[val].begin() );
        if(ump[val].size() == 0) ump.erase(val);

        // 将vector最后一个元素 移动到 deleteIndex处(这里 应该多余一个元素)
        if(deleteIndex != lastindex){
            ump[lastVal].erase(lastindex);
            ump[lastVal].insert(deleteIndex);
            recs[deleteIndex] = lastVal;
        }
        recs.pop_back();

        return res;        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if(recs.size() == 0) return -1;
        int index = rand() % recs.size();
        return recs[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */