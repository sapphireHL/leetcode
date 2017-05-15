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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps>pe) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int pos;
        for(int i=is; i<=ie; i++){
            if(inorder[i] == preorder[ps]){
                pos = i;
                break;
            }
        }
        root->left = build(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
        root->right = build(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
        return root;
    }
};
