class Solution {
public:
    void dfs(vector<int> candidates, vector<vector<int>>&res, vector<int> &p, int gap, int start){
        if(gap == 0){
            res.push_back(p);
            return;
        }
        int pre = -1;
        for(int i=start; i<candidates.size(); i++){
            if(gap < candidates[i]) return;
            if(pre == candidates[i]) continue;
            pre = candidates[i];
            p.push_back(candidates[i]);
            dfs(candidates, res, p, gap-candidates[i], i+1);
            p.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> p;
        dfs(candidates, res, p, target, 0);
        return res;
    }
};
