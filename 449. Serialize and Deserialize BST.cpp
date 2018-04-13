/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serialize(TreeNode* root, string& s) {
        if(root){
            s += to_string(root->val);
            s += ' ';
            serialize(root->left, s);
            serialize(root->right, s);
        }
        else
            s += "# ";
    }
    
    TreeNode* deserialize(istringstream& in) {
        string cur;
        if(in >> cur){
            if(cur == "#")
                return nullptr;
            TreeNode* root = new TreeNode(stoi(cur));
            root->left = deserialize(in);
            root->right = deserialize(in);
            return root;
        }
        else
            return nullptr;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
