class Solution {
public:
    void dfs(vector<int> candidates, vector<vector<int>>&res, vector<int> &p, map<int, int>& map, int gap, int start){
        if(gap == 0){
            res.push_back(p);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if(gap < candidates[i]) return;
            if(i>0 && candidates[i] == candidates[i-1] && map[candidates[i-1]] == 0) continue;
            map[candidates[i]] = 1;
            p.push_back(candidates[i]);
            dfs(candidates, res, p, map, gap-candidates[i], i+1);
            map[candidates[i]] = 0;
            p.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> p;
        map<int, int> map;
        dfs(candidates, res, p, map, target, 0);
        return res;
    }
};
