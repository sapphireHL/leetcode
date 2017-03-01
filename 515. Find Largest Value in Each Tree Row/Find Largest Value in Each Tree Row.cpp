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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode *> q;
        if(root == NULL)
            return result;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*> temp;
            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }
            int max = INT_MIN;
            for(int i=0; i<temp.size(); i++){
                if(temp[i]->left != NULL)
                    q.push(temp[i]->left);
                if(temp[i]->right != NULL)
                    q.push(temp[i]->right);
                if(max < temp[i]->val){
                    max = temp[i]->val;
                }
            }
            result.push_back(max);
        }
        return result;
    }
};
