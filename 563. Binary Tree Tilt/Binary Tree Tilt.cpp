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
    void dfs(TreeNode *root, int &res){
        if(root){
            dfs(root->left, res);
            dfs(root->right, res);
            int left = root->left?root->left->val:0;
            int right = root->right?root->right->val:0;
            res += abs(left-right);
            root->val += left+right;
        }
    }
    int findTilt(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
