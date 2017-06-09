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
    bool res = false;
    bool compare(TreeNode *s, TreeNode *t){
        if(s && t){
            return (s->val == t->val) && compare(s->left, t->left) && compare(s->right, t->right);
        }
        else if((s && !t) || (!s && t)) return false;
        else return true;
    }
    void traversal(TreeNode *s, TreeNode *t){
        if(s){
            traversal(s->left, t);
            traversal(s->right, t);
            if(compare(s, t)) res = true;
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        traversal(s, t);
        return res;
    }
};
