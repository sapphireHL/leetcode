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
    void gothrough(TreeNode *root, map<int, int> &m){
        if(root != NULL){
            m[root->val]++;
            gothrough(root->left, m);
            gothrough(root->right, m);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        map<int, int> m;
        gothrough(root, m);
        map<int, int>::iterator it = m.begin();
        if(it->second > 1){
            return 0;
        }
        int first = it->first;
        it++;
        while(it != m.end()){
            if(it->second > 1){
                return 0;
            }
            if(it->first -first < result){
                result = it->first - first;
            }
            first = it->first;
            it++;
        }
        
        return result;
    }
};
