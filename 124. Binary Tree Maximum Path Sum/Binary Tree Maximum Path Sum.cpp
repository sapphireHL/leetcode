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
    int maxsum(TreeNode* root, int &res){
        if(!root) return 0;
        int l = maxsum(root->left, res);
        int r = maxsum(root->right, res);
        if(l<0) l=0;
        if(r<0) r=0;
        res = max(res, l+r+root->val);
        return max(l, r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxsum(root, res);
        return res;
    }
};
