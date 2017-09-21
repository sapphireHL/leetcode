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
    int second = INT_MAX;
    void dfs(TreeNode* root, int minv){
        if(root){
            if(root->left && root->left->val == minv){
                if(root->right->val != minv) second = min(second, root->right->val);
                dfs(root->left, minv);
            }
            if(root->right && root->right->val == minv){
                if(root->left->val != minv) second = min(second, root->left->val);
                dfs(root->right, minv);
            }
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        int minv = root->val;
        dfs(root, minv);
        if(second == INT_MAX) return -1;
        return second;
    }
};
