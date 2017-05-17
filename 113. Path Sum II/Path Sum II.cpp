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
    void findpath(TreeNode* root, int sum, vector<int> tmp, vector<vector<int>>& res){
        if(!root) return;
        tmp.push_back(root->val);
        if(!root->left && !root->right && root->val==sum) res.push_back(tmp);
        findpath(root->left, sum-root->val, tmp, res);
        findpath(root->right, sum-root->val, tmp, res);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        findpath(root, sum, tmp, res);
        return res;
    }
};
