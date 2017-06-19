class Solution {
public:
    void dfs(vector<vector<string>>& res, vector<string>& queen, vector<int>& column_flag, vector<int>& dia45_flag,vector<int>& dia135_flag,int row, int n){
        if(row == n){
            res.push_back(queen);
            return;
        }
        for(int col=0; col<n; col++){
            if(column_flag[col] && dia45_flag[row+col] && dia135_flag[n-1-(row-col)]){
                queen[row][col] = 'Q';
                column_flag[col] = 0;
                dia45_flag[row+col] = 0;
                dia135_flag[n-1-(row-col)] = 0;
                dfs(res, queen, column_flag, dia45_flag, dia135_flag, row+1, n);
                queen[row][col] = '.';
                column_flag[col] = 1;
                dia45_flag[row+col] = 1;
                dia135_flag[n-1-(row-col)] = 1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> queen(n, string(n, '.'));
        vector<int> column_flag(n, 1);
        vector<int> dia45_flag(2*n-1, 1);
        vector<int> dia135_flag(2*n-1, 1);
        dfs(res, queen, column_flag, dia45_flag, dia135_flag, 0, n);
        return res;
    }
};
