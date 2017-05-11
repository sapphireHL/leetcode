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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
    	stack<vector<int>> s;
    	queue<TreeNode *> q;
    	int count=0;
    	if(root != NULL) q.push(root);
    	while(!q.empty()){
    	    vector<TreeNode*> tmp;
    	    while(!q.empty()){
    	        tmp.push_back(q.front());
    	        q.pop();
    	    }
    	    res.resize(res.size()+1);
    	    for(int i=0; i<tmp.size(); i++){
	            if(tmp[i]->left != NULL) q.push(tmp[i]->left);
	            if(tmp[i]->right != NULL) q.push(tmp[i]->right);
    	    }
    	    if(count%2==1){
    	        for(int i=tmp.size()-1; i>=0; i--)
    	            res[count].push_back(tmp[i]->val);
    	    }
    	    else{
    	        for(int i=0; i<tmp.size(); i++)
    	            res[count].push_back(tmp[i]->val);
    	    }
    	    count++;
    	}
    	return res;
    }
};
