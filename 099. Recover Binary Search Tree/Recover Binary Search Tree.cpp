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
    int pre = INT_MIN;
    TreeNode *prev, *first, *n1, *n2;
    void inorder(TreeNode *root){
        if(root != NULL){
            inorder(root->left);
            if(root->val < pre){
                if(n1 == NULL){
                    n1 = prev;
                    first = root;
                }
                else
                    n2 = root;
            }
            pre=root->val;
            prev = root;
            inorder(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        inorder(root);
        if(n2==NULL)
            n2 = first;
        swap(n1->val, n2->val);
    }
};
