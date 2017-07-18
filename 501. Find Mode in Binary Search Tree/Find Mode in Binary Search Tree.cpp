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
    TreeNode* prev;
    int maxf=0, curf=0, counts=0;
    void count(TreeNode* root){
        if(root){
            counts++;
            count(root->left);
            count(root->right);
        }
    }
    void inorder(TreeNode* root, vector<int>& res){
        if(root){
            inorder(root->left, res);
            counts--;
            if(!prev || prev->val == root->val){
                curf++;
            }
            else{
                if(curf == maxf) res.push_back(prev->val);
                else if(curf > maxf) {
                    res.clear();
                    res.push_back(prev->val);
                    maxf = curf;
                }
                curf=1;
            }
            if(counts==0){
                if(curf == maxf) res.push_back(root->val);
                else if(curf > maxf) {
                    res.clear();
                    res.push_back(root->val);
                }
            }
            prev = root;
            inorder(root->right, res);
        }
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        count(root);
        inorder(root, res);
        return res;
    }
};
