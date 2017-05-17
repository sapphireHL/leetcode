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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> nul;
        if(n == 0) return nul;
        return generate(1, n);
    }
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> sub;
        if(start > end){
            sub.push_back(NULL);
            return sub;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left = generate(start, i-1);
            vector<TreeNode*> right = generate(i+1, end);
            for(auto j:left){
                for(auto k:right){
                    TreeNode* node = new TreeNode(i);
                    node->left = j;
                    node->right = k;
                    sub.push_back(node);
                }
            }
        }
        return sub;
    }
};
