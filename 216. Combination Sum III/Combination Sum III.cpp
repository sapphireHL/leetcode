class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int> &p, int k, int gap, int start){
        if(p.size() == k){
            if(gap == 0) res.push_back(p);
            return;
        }
        for(int i=start; i<=9; i++){
            if(gap < i) return;
            p.push_back(i);
            dfs(res, p, k, gap-i, i+1);
            p.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> p;
        dfs(res, p, k, n, 1);
        return res;
    }
};
