/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root){
            TreeLinkNode *pre = NULL;
            TreeLinkNode *next = NULL;
            while(root){
                if(!next) next = root->left?root->left:root->right;
                if(root->left){
                    if(pre) pre->next = root->left;
                    pre = root->left;
                }
                if(root->right){
                    if(pre) pre->next = root->right;
                    pre = root->right;
                }
                root = root->next;
            }
            root = next;
        }
    }
};
