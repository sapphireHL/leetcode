class Solution {
public:
    bool isvalid(vector<string> queen, int row, int col){
        for(int i=0; i<row; i++){
            if(queen[i][col]=='Q') return false;
        }
        for(int i=row-1, j=col-1; i>=0&&j>=0; i--, j--)
            if(queen[i][j] == 'Q') return false;
        for(int i=row-1, j=col+1; i>=0&&j<queen.size(); i--, j++)
            if(queen[i][j] == 'Q') return false;
        return true;
    }
    void dfs(vector<vector<string>>& res, vector<string>& queen, int row, int n){
        if(row == n){
            res.push_back(queen);
            return;
        }
        for(int col=0; col<n; col++){
            if(isvalid(queen, row, col)){
                queen[row][col] = 'Q';
                dfs(res, queen, row+1, n);
                queen[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> queen(n, string(n, '.'));
        dfs(res, queen, 0, n);
        return res;
    }
};
