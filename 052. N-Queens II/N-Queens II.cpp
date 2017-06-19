class Solution {
public:
    void dfs(int n, int& res, vector<int>& path, vector<int>& flag, vector<int>& flag45, vector<int>&flag135, int row){
        if(path.size() == n){
            res++;
            return;
        }
        for(int col = 0; col<n; col++){
            if(flag[col] && flag45[col+row] && flag135[n-1-(row-col)]){
                flag[col] = 0;
                flag45[col+row] = 0;
                flag135[n-1-(row-col)] = 0;
                path.push_back(col);
                dfs(n, res, path, flag, flag45, flag135, row+1);
                flag[col] = 1;
                flag45[col+row] = 1;
                flag135[n-1-(row-col)] = 1;
                path.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        int res=0;
        vector<int> flag(n, 1), flag45(2*n-1, 1), flag135(2*n-1, 1), path;
        dfs(n, res, path, flag, flag45, flag135, 0);
        return res;
    }
};
