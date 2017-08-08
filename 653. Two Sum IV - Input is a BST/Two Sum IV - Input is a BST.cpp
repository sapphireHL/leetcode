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
    unordered_map<int, int> m;
    bool flag = false;
    void traversal(TreeNode* root, int k){
        if(flag) return;
        if(root){
            m[root->val]++;
            if(k == 2*root->val){
                if(m[root->val] >= 2) flag = true;
            }
            else if(m.find(k-root->val)!=m.end()){
                flag = true;
            }
            traversal(root->left, k);
            traversal(root->right, k);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        traversal(root, k);
        return flag;
    }
};
