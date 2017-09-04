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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return nullptr;
        if(root->val < L) return trimBST(root->right, L, R);
        else if(root->val > R) return trimBST(root->left, L, R);
        TreeNode* newroot = new TreeNode(root->val);
        TreeNode* l = trimBST(root->left, L, R);
        TreeNode* r = trimBST(root->right, L, R);
        newroot->left = l;
        newroot->right = r;
        return newroot;
    }
};
