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
    void inorderTraversal(TreeNode *root, int &min, int &pre){
        if(root != NULL){
            inorderTraversal(root->left, min, pre);
            if(root->val - pre < min){
                min = root->val - pre;
            }
            pre = root->val;
            inorderTraversal(root->right, min, pre);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        int min = INT_MAX, pre = root->val-INT_MAX;
        inorderTraversal(root, min, pre);
        return min;
    }
};
