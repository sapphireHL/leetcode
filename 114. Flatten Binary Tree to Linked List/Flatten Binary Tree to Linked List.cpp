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
    void pre(TreeNode *root, vector<int> &v){
        if(root != NULL){
            v.push_back(root->val);
            pre(root->left, v);
            pre(root->right, v);
        }
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode *cur = root;
        vector<int> v;
        pre(root, v);
        root->right = NULL;
        root->left = NULL;
        for(int i=1; i<v.size(); i++){
            cur->right = new TreeNode(v[i]);
            cur = cur->right;
        }
    }
};
