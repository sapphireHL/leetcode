class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int> &path, vector<int>&nums){
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(find(path.begin(), path.end(), nums[i]) == path.end()){
                path.push_back(nums[i]);
                dfs(res, path, nums);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, nums);
        return res;
    }
};
