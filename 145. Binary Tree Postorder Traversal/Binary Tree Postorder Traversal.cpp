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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *p = root, *q=NULL;//p当前节点，q访问过的前一个节点
        while(!s.empty() || p!=NULL){
            while(p != NULL){
                s.push(p);
                p = p->left;
            }
            p=s.top();
            //若p右节点为空或访问过，访问当前节点
            if(p->right == q || p->right == NULL){
                res.push_back(p->val);
                q = p;
                s.pop();
                p=NULL;
            }
            else{
                p = p->right;
            }
        }
        return res;
    }
};
