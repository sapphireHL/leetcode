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
    TreeNode* generate(vector<int>& nums, int start, int end){
        TreeNode* root=NULL;
        if(start > end) return root;
        int mid = (start+end+1)/2;
        root = new TreeNode(nums[mid]);
        root->left = generate(nums, start, mid-1);
        root->right = generate(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return generate(nums, 0, nums.size()-1);
    }
};
