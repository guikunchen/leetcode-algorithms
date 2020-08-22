// https://leetcode-cn.com/problems/construct-quad-tree/


class Solution {// 
public:// 和二叉树的创建基本相同，只是多创建两个子树。
    Node* construct(vector<vector<int>>& grid) {
        this->grid = grid;
        int w = grid.size();
        Node* node = dfs(0, 0, w);
        return node;
        
    }
private:
    vector<vector<int>> grid;
    Node* dfs(int x, int y, int w){
        if(w == 1){                                 //如果只剩最后一个数字，那么直接创建一个四叉树节点
            Node* node = new Node(grid[x][y], 1);
            return node;
        }
        if(isequal(x,y,w)){                         //如果矩形框内的数字都相同，那么也直接创建一个四叉树节点
            Node* node = new Node(grid[x][y], 1);
            return node;
        }
        Node* __topLeft = dfs(x, y, w / 2);         //如果矩形框内的数字不相同，先创建4个子树，最后创建父节点
        Node* __topRight = dfs(x, y + w / 2, w / 2);
        Node* __bottomLeft = dfs(x  + w / 2, y, w / 2);
        Node* __bottomRight = dfs(x + w / 2, y + w / 2, w / 2);
        Node* node = new Node(1, 0, __topLeft, __topRight, __bottomLeft, __bottomRight);
        return node;
    }
    bool isequal(int x, int y, int w){
        int a = grid[x][y];
        for(int i = x; i < x + w; i++)
            for(int j = y; j < y + w; j++){
                if(a != grid[i][j])
                    return false;
            }
        return true;
    }
};