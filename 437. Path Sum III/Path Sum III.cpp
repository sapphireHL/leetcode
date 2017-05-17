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
    void psum(TreeNode* root, int sum, int &res){
        if(!root) return;
        if(sum == root->val) res++;
        psum(root->left, sum-root->val, res);
        psum(root->right, sum-root->val, res);
    }
    void traversal(TreeNode* root, int sum, int &res){
        if(root){
            psum(root, sum, res);
            traversal(root->left, sum, res);
            traversal(root->right, sum, res);
        }
    }
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        traversal(root, sum, res);
        return res;
    }
};
