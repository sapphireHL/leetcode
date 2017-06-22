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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d < 2){
            TreeNode* newroot = new TreeNode(v);
            (d==1?newroot->left:newroot->right) = root;
            return newroot;
        }
        if(root){
            root->left = addOneRow(root->left, v, d>2?d-1:1);
            root->right = addOneRow(root->right, v, d>2?d-1:0);
        }
        return root;
    }
};
