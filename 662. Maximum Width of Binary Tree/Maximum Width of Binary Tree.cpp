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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int size = q.size(), left = 0, right = 0;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(i == 0) left = cur->val;
                if(i == size-1) right = cur->val;
                if(cur){
                    if(cur->left){
                        cur->left->val = cur->val*2;
                        q.push(cur->left);
                    }
                    if(cur->right){
                        cur->right->val = cur->val*2 + 1;
                        q.push(cur->right);
                    }
                }
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
