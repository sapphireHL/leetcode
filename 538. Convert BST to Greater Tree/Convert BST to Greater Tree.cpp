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
    int count = 0, pre = 0;
    void intraversal(TreeNode *root){
        if(root != NULL){
            intraversal(root->right);
            root->val += pre;
            pre = root->val;
            intraversal(root->left);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        TreeNode *result = root;
        intraversal(root);
        return result;
    }
};
