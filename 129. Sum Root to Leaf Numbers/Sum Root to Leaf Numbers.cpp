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
    void sum(TreeNode* root, int add, int &res){
        if(!root) return;
        add = add*10 + root->val;
        if(!root->left && !root->right)
            res+=add;
        sum(root->left, add, res);
        sum(root->right, add, res);
    }
    int sumNumbers(TreeNode* root) {
        int res=0, add=0;
        sum(root, add, res);
        return res;
    }
};
