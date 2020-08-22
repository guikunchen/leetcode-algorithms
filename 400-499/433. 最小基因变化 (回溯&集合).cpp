// https://leetcode-cn.com/problems/minimum-genetic-mutation/
/*一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 "A", "C", "G", "T"中的任意一个。

假设我们要调查一个基因序列的变化。一次基因变化意味着这个基因序列中的一个字符发生了变化。

例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。

与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。

现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。如果无法实现目标变化，请返回 -1。*/ 
class Solution {// BFS
public:
    int minMutation(string start, string end, vector<string>& bank) {

        //记录所有需要访问的节点
        unordered_set<string> candidate(bank.begin(), bank.end());
        //记录基因和step
        queue<pair<string ,int>> q;

        q.push({start, 0});

        string gene;
        int step;

        while( ! q.empty()) {
            //终止条件
            if (q.front().first == end){
                return q.front().second;
            }

            gene = q.front().first;
            step = q.front().second;
            q.pop();

            for (int i = 0; i < gene.length(); i++){
                char tmp =  gene[i]; //记录原状态
                for (char base : "ATCG"){
                    if (gene[i] == base) continue; //相同就不变化
                    gene[i] = base; //修改碱基
                    if( candidate.find(gene) != candidate.end()){
                        q.push({gene, step+1});
                        candidate.erase(gene);
                    }
                }
                gene[i] = tmp;

            }
        }
        return -1;

    }
};