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
    bool issame(TreeNode *a, TreeNode *b){
        if(a!=NULL && b!=NULL &&a->val == b->val){
            return issame(a->left, b->right) && issame(a->right, b->left);
        }
        else if(a==NULL && b==NULL) return true;
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return issame(root->left, root->right);
    }
};
