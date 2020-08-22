// https://leetcode-cn.com/problems/longest-absolute-file-path/
/*字符串 "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" 表示:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
目录 dir 包含两个子目录 subdir1 和 subdir2。 subdir1 包含一个文件 file1.ext 和一个空的二级子目录 subsubdir1。subdir2 包含一个二级子目录 subsubdir2 ，其中包含一个文件 file2.ext。

我们致力于寻找我们文件系统中文件的最长 (按字符的数量统计) 绝对路径。例如，在上述的第二个例子中，最长路径为 "dir/subdir2/subsubdir2/file2.ext"，其长度为 32 (不包含双引号)。*/
class Solution {
public:
    int lengthLongestPath(string input) {
        int starter = 0;
        int res = 0;
        int curLen = 0; // 在一条路径内更新路径长度
        int last_level = -1; // 上一行的层次
        stack<pair<string, int>> stk; // 要始终保证栈中只有一条路径；string为当前结点名，int为当前结点层次
        for (int i = 0; i <= input.size(); i++) {
            if (i == input.size() || input[i] == '\n') { // 取starter到i之间的结点
                string node = input.substr(starter, i - starter);
                starter = i + 1; // 更新starter
                int j = 0;
                for (; j < node.size() && node[j] == '\t'; j++); // 确定当前结点是第几层目录
                while (j <= last_level && !stk.empty()) { // 说明上一行结束了一个完整的路径
                    curLen -= stk.top().first.size(); // 需要将当前路径的长度回滚
                    stk.pop();
                    if (!stk.empty())
                        last_level = stk.top().second;
                } // 此时stk.top()是当前结点node的上一层
                // last_level是当前结点node的上一层的层次，也就是j - 1
                // curLen是当前结点node的上一层的长度
                last_level = j;
                string node_without_t = node.substr(j);
                stk.push(make_pair(node_without_t, j));
                curLen += node_without_t.size();
                if (node_without_t.find('.') != -1) {
                    // 说明当前结点是一个文件，可以更新res
                    res = max(res, curLen + j); // 注意'/'的个数等于j，需要加上
                }
            }
        }
        return res;
    }
};