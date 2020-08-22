// https://leetcode-cn.com/problems/sort-characters-by-frequency/

class Solution {// 优先队列
public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for (const auto &c : s) {
            ++ump[c];
        }
        priority_queue<pair<int, char>> pq;
        for (const auto &m : ump) {
            pq.push({m.second, m.first});
        }        
        string ret;
        while (!pq.empty()) {
            auto t = pq.top(); 
            pq.pop();
            ret.append(t.first, t.second);
        }
        return ret;
    }
};

// 每个字符出现次数不会超过字符串s长度，
// 将字符添加到字符出现次数对应数组下标处，
// 然后从后向前遍历，如果对应下标不为空，则添加到结果集中。
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for (const auto &c : s) {
            ++ump[c];
        }
        vector<string> vec(s.size() + 1);
        string res;
        for (const auto &m : ump) {
            vec[m.second].append(m.second, m.first);
        }
        for (int i = s.size(); i > 0; --i) {
            if (!vec[i].empty()) {
                res.append(vec[i]);
            }
        }
        return res;
    }
};