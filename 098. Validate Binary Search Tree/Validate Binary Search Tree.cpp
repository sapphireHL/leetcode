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
    TreeNode* pre = NULL;
    bool flag = true;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            if(pre && root->val <= pre->val) flag = false;
            pre = root;
            inorder(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return flag;
    }
};
