class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "null";
        string temp = "";
        temp += to_string(root->val) + ",";
        temp += serialize(root->left) + ",";
        temp += serialize(root->right);
        return temp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return rdeserialize(is);
    }

    TreeNode* rdeserialize(istringstream& is) {
        string temp;
        getline(is, temp, ',');
        if (temp == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(temp));
        root->left = rdeserialize(is);
        root->right = rdeserialize(is);
        return root;
    }
};