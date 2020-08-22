// https://leetcode-cn.com/problems/sequence-reconstruction

/*验证原始的序列 org 是否可以从序列集 seqs 中唯一地重建。
序列 org 是 1 到 n 整数的排列，其中 1 ≤ n ≤ 104。
重建是指在序列集 seqs 中构建最短的公共超序列。（即使得所有 seqs 中的序列都是该最短序列的子序列）。
确定是否只可以从 seqs 重建唯一的序列，且该序列就是 org 。

示例 1：
输入：
org: [1,2,3], seqs: [[1,2],[1,3]]
输出：
false
解释：
[1,2,3] 不是可以被重建的唯一的序列，因为 [1,3,2] 也是一个合法的序列。
 
示例 2：
输入：
org: [1,2,3], seqs: [[1,2]]
输出：
false
解释：
可以重建的序列只有 [1,2]。
 
示例 3：
输入：
org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
输出：
true
解释：
序列 [1,2], [1,3] 和 [2,3] 可以被唯一地重建为原始的序列 [1,2,3]。*/
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int cur = 0;
        for(int i = 0, j = 0; i < n; j = i) {// i会指向下一个字符串，每次滑动窗口ij在同一位置
            while(i < n && chars[i] == chars[j]) {
                i++;
            }
            chars[cur++] = chars[j];
            if(i - j == 1) {
                continue;
            }
            string s = to_string(i - j);
            for(int t = 0; t < s.size(); t++) {
                chars[cur++] = s[t];
            }
        }
        return cur;
    }
};

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<bool> exit(n+1, false);//是否存在
        vector<vector<int>> g(n+1);//图
        vector<int> indegree(n+1, 0);//入度
        for(auto& s : seqs)
        {
            int from = -1;
            for(int i = 0; i < s.size(); ++i)
            {
                if(s[i] <= 0 || s[i] > n) return false;//编号超了
                exit[s[i]] = true;
                if(from != -1)
                {
                    g[from].push_back(s[i]);//边
                    indegree[s[i]]++;//入度+1
                }
                from = s[i];
            }
        }
        queue<int> q;
        for(int i = 1; i <= n; ++i)
        {
            if(!exit[i]) return false;//有的点不存在
            if(indegree[i]==0)//入度为0的入队
                q.push(i);
        }
        int i = 0;
        while(!q.empty())
        {
            if(q.size() != 1) return false;//选择不唯一
            int cur = q.front();
            if(cur != org[i++]) return false;//跟序列不匹配
            q.pop();
            for(int i = 0; i < g[cur].size(); ++i)
            {
                if(--indegree[g[cur][i]] == 0)
                    q.push(g[cur][i]);//入队为0 的入队
            }
        }
        if(i != n) return false;//有环
        return true;
    }
};