class Solution {
public:
    void dfs(int n, int l, int r, vector<string>&res, string path){
        if(l == n){
            for(int i=0; i<n-r; i++) path+=')';
            res.push_back(path);
            return;
        }
        dfs(n, l+1, r, res, path+"(");
        if(r<l){
            dfs(n, l, r+1, res, path+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        dfs(n, 0, 0, res, path);
        return res;
    }
};
