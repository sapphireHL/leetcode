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
    void tsum(TreeNode *root, int &sum){
        if(root != NULL){
            sum += root->val;
            tsum(root->left, sum);
            tsum(root->right, sum);
        }
    }
    void gothrough(TreeNode *root, vector<int>& sums){
        if(root != NULL){
            int sum = 0;
            tsum(root, sum);
            sums.push_back(sum);
            gothrough(root->left, sums);
            gothrough(root->right, sums);
        }
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        vector<int> sums;
        if(root == NULL){
            return result;
        }
        gothrough(root, sums);
        
        int maxcount = 0;
        map<int, int> m;
        for(int i=0; i<sums.size(); i++){
            m[sums[i]]++;
        }
        map<int, int>::iterator it = m.begin();
        while(it != m.end()){
            if(it->second > maxcount){
                maxcount = it->second;
            }
            it++;
        }
        if(maxcount == 1){
            return sums;
        }
        it = m.begin();
         while(it != m.end()){
            if(it->second == maxcount){
                result.push_back(it->first);
            }
            it++;
        }
        return result;
    }
};
