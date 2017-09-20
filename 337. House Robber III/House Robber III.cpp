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
    vector<int> robsub(TreeNode* root){
        if(!root) return vector<int>(2, 0);
        vector<int> left = robsub(root->left);
        vector<int> right = robsub(root->right);
        vector<int> cur(2);
        cur[0] = max(left[0], left[1]) + max(right[0], right[1]);
        cur[1] = root->val + left[0] + right[0];
        return cur;
    }
    int rob(TreeNode* root) {
        vector<int> res = robsub(root);
        //0不抢  1抢
        return max(res[0], res[1]);
    }
};
