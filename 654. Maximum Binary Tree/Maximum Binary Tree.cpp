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
    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left > right) return nullptr;
        int maxv = INT_MIN, maxpos = 0;
        for(int i = left; i <= right; i++){
            if(nums[i] > maxv){
                maxv = nums[i];
                maxpos = i;
            }
        }
        TreeNode* newroot = new TreeNode(maxv);
        newroot->left = helper(nums, left, maxpos-1);
        newroot->right = helper(nums, maxpos+1, right);
        return newroot;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};
