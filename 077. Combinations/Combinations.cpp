class Solution {
public:
    void dfs(vector<vector<int>>&res, vector<int>&path, int k, int n, int start){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        for(int i=start; i<=n; i++){
            path.push_back(i);
            dfs(res, path, k, n, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, k, n, 1);
        return res;
    }
};
