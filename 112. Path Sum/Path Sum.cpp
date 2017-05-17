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
    bool flag = false;
    void pathsum(TreeNode* root, int add, int sum){
        if(root){
            add += root->val;
            if(!root->left && !root->right)
                if(add == sum) flag = true;
            pathsum(root->left, add, sum);
            pathsum(root->right, add, sum);
        }
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right) return sum == root->val;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
