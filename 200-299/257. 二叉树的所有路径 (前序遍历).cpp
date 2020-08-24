#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/binary-tree-paths/
// 给定一个二叉树，返回所有从根节点到叶子节点的路径。
class Solution {   //先序遍历
public:
    vector<string> vs;  //用来保存每一个路径， 定义在dfs之外 比较好操作
    vector<string> binaryTreePaths(TreeNode *root) {
        string path; //与root一并传入，走出一个dfs的路径
        dfs(root, path);
        return vs;  
    }
    void dfs(TreeNode *root, string path) { //先序遍历 遇到结点先访问  
        if (root != NULL) {      //path永远都是一个拷贝，修改left or right的path 与上一个path无关，即保留住前面的 未走到叶节点的路径
            path += to_string(root->val) ;   // 因此 每一个path一直＋ root->val即可，走完叶节点之后，函数会返回到之前的path继续找叶节点
            if (root->left == NULL && root->right == NULL) 
                vs.push_back(path);    //叶节点对应的path  就是路径了 直接push到vector中
            else
                path += "->";  //不是叶节点 就+上 ->
            dfs(root->left, path);  //先序遍历左子树
            dfs(root->right, path);  //先序遍历右子树
        }
    }
};

class Solution {// 双队列，一个存节点一个存路径
    public List<String> binaryTreePaths(TreeNode root) {
        LinkedList<String> paths = new LinkedList();
        if (root == null)
            return paths;

        LinkedList<TreeNode> node_stack = new LinkedList();
        LinkedList<String> path_stack = new LinkedList();
        node_stack.add(root);
        path_stack.add(Integer.toString(root.val));
        TreeNode node;
        String path;
        while (!node_stack.isEmpty()) {
            node = node_stack.pollLast();
            path = path_stack.pollLast();
            if ((node.left == null) && (node.right == null))
                paths.add(path);
            if (node.left != null) {
                node_stack.add(node.left);
                path_stack.add(path + "->" + Integer.toString(node.left.val));
            }
            if (node.right != null) {
                node_stack.add(node.right);
                path_stack.add(path + "->" + Integer.toString(node.right.val));
            }
        }
        return paths;
    }
}