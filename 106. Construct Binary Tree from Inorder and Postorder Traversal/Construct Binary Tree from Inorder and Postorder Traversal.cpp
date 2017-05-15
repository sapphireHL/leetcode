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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe){
        if(ps>pe) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int pos;
        for(int i=is; i<=ie; i++){
            if(inorder[i] == postorder[pe]){
                pos = i;
                break;
            }
        }
        int leftsize = pos-is;
        root->left = build(inorder, postorder, is, pos-1, ps, ps+leftsize-1);
        root->right = build(inorder, postorder, pos+1, ie, ps+leftsize, pe-1);
        return root;
    }
};
