// https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/

class Codec {
public:

    //1、前序
    string serialize(TreeNode* root) {

        if (!root)
        {
            return "#,";
        }

        string s = to_string(root->val) + ",";
        s += serialize(root->left);
        s += serialize(root->right);

        return s;
    }

    TreeNode* deserialize(const vector<string>& arr, int& index)
    {
        const string& s = arr.at(index++);
        if (s == "#")
        {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(s));
        node->left = deserialize(arr, index);
        node->right = deserialize(arr, index);

        return node;
    }


    TreeNode* deserialize(string data) {

        vector<string> arr = split(data, ",");
        int index = 0;
        TreeNode* root = deserialize(arr, index);
        return root;
    }


    //2、层序
    string serialize(TreeNode* root) {

        if (root == nullptr)
        {
            return "#,";
        }

        string s = to_string(root->val) + ",";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if (node->left)
            {
                q.push(node->left);
                s += to_string(node->left->val) + ",";
            }
            else
            {
                s += "#,";
            }

            if (node->right)
            {
                q.push(node->right);
                s += to_string(node->right->val) + ",";
            }
            else
            {
                s += "#,";
            }
        }

        return s;
    }


    TreeNode* deserialize(string data) {

        //分割字符串
        vector<string> v = split(data, ",");

        queue<TreeNode*> q;

        int index = 0;
        TreeNode* root = generate_node(v.at(index++));
        if (root) //root可能为空  如：data为"#,"
        {
            q.push(root);
        }

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            node->left = generate_node(v.at(index++));
            if (node->left)
            {
                q.push(node->left);
            }

            node->right = generate_node(v.at(index++));
            if (node->right)
            {
                q.push(node->right);
            }
        }

        return root;
    }


    vector<string> split(string& data, const string& delim)
    {
        vector<string> res;
        char* str = strtok((char*)data.c_str(), delim.c_str());
        while (str)
        {
            res.push_back(str);
            str = strtok(NULL, ",");
        }
        return res;
    }

    TreeNode* generate_node(const string& data)
    {
        if (data == "#")
        {
            return nullptr;
        }
        return new TreeNode(stoi(data));
    }
};