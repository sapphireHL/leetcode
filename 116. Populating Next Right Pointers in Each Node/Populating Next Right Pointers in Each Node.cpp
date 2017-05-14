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
        if(root == NULL) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<TreeLinkNode *> tmp;
            while(!q.empty()){
                tmp.push_back(q.front());
                q.pop();
            }
            for(int i=0; i<tmp.size()-1; i++){
                tmp[i]->next = tmp[i+1];
            }
            tmp[tmp.size()-1]->next = NULL;
            for(int i=0; i<tmp.size(); i++){
                if(tmp[i]->left) q.push(tmp[i]->left);
                if(tmp[i]->right) q.push(tmp[i]->right);
            }
        }
    }
};
