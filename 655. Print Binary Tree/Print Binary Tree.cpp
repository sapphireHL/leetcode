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
    int height(TreeNode* root){
        if(root){
            int left = height(root->left);
            int right = height(root->right);
            return max(left, right)+1;
        }
        else
            return 0;
    }
    
    void dfs(TreeNode* root, vector<vector<string>> &res, int h, int start, int end){
        int mid = start+(end-start)/2;
        res[h][mid] = to_string(root->val);
        if(root->left)
            dfs(root->left, res, h+1, start, mid-1);
        if(root->right)
            dfs(root->right, res, h+1, mid+1, end);
    }
    
    void bfs(TreeNode* root, vector<vector<string>> &res, int h, int w){
        queue<TreeNode*> q;
        q.push(root);
        int step = 1;
        while(step <= h){
            int size = q.size();
            int j = w / (1<<step);
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur){
                    q.push(cur->left);
                    q.push(cur->right);
                    res[step-1][j] = to_string(cur->val);
                }
                else{
                    q.push(nullptr);
                    q.push(nullptr);
                }
                j += (1<<(h-step+1));
            }
            step++;
        }
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int w = (1<<h)-1;
        vector<vector<string>> res(h, vector<string>(w));
        //dfs(root, res, 0, 0, w-1);
        bfs(root, res, h, w);
        
        return res;
    }
};
