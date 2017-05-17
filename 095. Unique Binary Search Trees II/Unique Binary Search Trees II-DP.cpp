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
    TreeNode* clone(TreeNode* root){
        if(root == NULL) return NULL;
        TreeNode* newroot = new TreeNode(root->val);
        newroot->left = clone(root->left);
        newroot->right = clone(root->right);
        return newroot;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> sub;
        if(n == 0) return sub;
        sub.resize(1);
        for(int i=1; i<=n; i++){
            vector<TreeNode*> tmp;
            for(int j=0; j<sub.size(); j++){
                TreeNode* oldroot = sub[j];
                TreeNode* clo = clone(oldroot);
                TreeNode* newroot = new TreeNode(i);
                newroot->left = clo;
                tmp.push_back(newroot);
                
                if(oldroot!=NULL){
                    TreeNode* oldp = oldroot;
                    while(oldp->right!=NULL){
                        TreeNode* newr = new TreeNode(i);
                        TreeNode* oldright = oldp->right;
                        oldp->right = newr;
                        newr->left = oldright;
                        TreeNode* clo = clone(oldroot);
                        tmp.push_back(clo);
                        oldp->right = oldright;
                        oldp = oldp->right;
                    }
                    oldp->right = new TreeNode(i);
                    TreeNode* clo = clone(oldroot);
                    tmp.push_back(clo);
                    oldp->right = NULL;
                }
            }
            sub = tmp;
        }
        return sub;
    }
};
