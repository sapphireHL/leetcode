class Solution {
public:
    set<vector<int>> s;
    vector<int> path;
    void dfs(vector<int>& nums, int start, int n){
        if(path.size() >= 2)
            s.insert(path);
        for(int i=start; i<n; i++){
            if(path.empty() || nums[i] >= path.back()){
                path.push_back(nums[i]);
                dfs(nums, i+1, n);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        const int n = nums.size();
        dfs(nums, 0, n);
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};
