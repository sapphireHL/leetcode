/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int flag = 0;
    void preorder(TreeNode*root, vector<string>&res, vector<string>& path){
        if(!root){
            if(flag){
                string tmp = path.front();
                for(int i=1; i<path.size(); i++) tmp += "->"+path[i];
                res.push_back(tmp);
                flag=0;
            } 
        }
        else{
            path.push_back(to_string(root->val));
            if(!root->left && !root->right) flag=1;
            preorder(root->left, res, path);
            preorder(root->right, res, path);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res, path;
        preorder(root, res, path);
        return res;
    }
};
