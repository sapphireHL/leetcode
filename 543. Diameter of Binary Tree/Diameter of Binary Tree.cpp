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
    int height(TreeNode* root, int& res){
        if(root){
            int left = height(root->left, res);
            int right = height(root->right, res);
            res = max(res, left+right);
            return max(left, right)+1;
        }
        else return 0;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        height(root, res);
        return res;
    }
};
