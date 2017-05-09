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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        if (root != NULL) s.push(root);
        while(!s.empty()){
            TreeNode *temp = s.top();
            cout<<temp->val<<' ';
            s.pop();
            if(temp->right != NULL) s.push(temp->right);
            if(temp->left != NULL) s.push(temp->left);
            res.push_back(temp->val);
        }
        return res;
    }
};
