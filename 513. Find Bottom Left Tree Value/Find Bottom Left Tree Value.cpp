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
    int findBottomLeftValue(TreeNode* root) {
        int result = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->right != NULL)
                q.push(temp->right);
            if(temp->left != NULL)
                q.push(temp->left);
            result = temp->val;
        }
        return result;
    }
};
