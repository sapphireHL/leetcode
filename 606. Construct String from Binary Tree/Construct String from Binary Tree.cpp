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
    void dfs(TreeNode*root, TreeNode* t, string &res){
        if(t){
            if(t != root) res += '(';
            res += to_string(t->val);
            if(!t->left && t->right) res += "()";
            dfs(root, t->left, res);
            dfs(root, t->right, res);
            if(t != root) res += ')';
        }
    }
    string tree2str(TreeNode* t) {
        string res;
        if(!t) return res;
        dfs(t, t, res);
        return res;
    }
};
