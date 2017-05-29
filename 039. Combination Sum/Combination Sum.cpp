class Solution {
public:
    void dfs(vector<vector<int>>&res, vector<int>&p, vector<int>& candidates, int gap, int start){
        if(gap == 0){
            res.push_back(p);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if(gap < candidates[i]) return;
            p.push_back(candidates[i]);
            dfs(res, p, candidates, gap-candidates[i], i);
            p.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> p;
        dfs(res, p, candidates, target, 0);
        return res;
    }
};
