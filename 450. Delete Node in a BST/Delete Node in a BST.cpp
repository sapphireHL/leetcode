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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(!root->left)
                return root->right;
            else if(!root->right)
                return root->left;
            else{
                //找到右子树中最小的值
                auto right = root->right;
                while(right->left){
                    right = right->left;
                }
                root->val = right->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};
