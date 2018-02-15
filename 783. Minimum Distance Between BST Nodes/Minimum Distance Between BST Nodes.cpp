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
    int pre = 0;
    int count = 0;
    int res = INT_MAX;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            if(count++ != 0){
                res = min(res, abs(root->val - pre));
            }
            pre = root->val;   
            inorder(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        inorder(root);
        return res;
    }
};
