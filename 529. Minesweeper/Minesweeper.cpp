class Solution {
public:
    int mine(vector<vector<char>>& board, int i, int j){
        int res = 0;
        int starti = i-1>=0?i-1:i;
        int endi = i+1<board.size()?i+1:i;
        int startj = j-1>=0?j-1:j;
        int endj = j+1<board[i].size()?j+1:j;
        for(int i=starti; i<=endi; i++){
            for(int j=startj; j<=endj; j++){
                if(board[i][j] == 'M') res++;
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, int i, int j,vector<vector<bool>> & visited, int m, int n){
        if(!visited[i][j] && board[i][j] == 'E'){
            visited[i][j] = true;
            int num = mine(board, i, j);
            if(num > 0) {
                board[i][j] = num+'0';
                return;
            }
            board[i][j] = 'B';
            if(i-1>=0) dfs(board, i-1, j, visited, m, n);
            if(i+1<m)  dfs(board, i+1, j, visited, m, n);
            if(j-1>=0) dfs(board, i, j-1, visited, m, n);
            if(j+1<n)  dfs(board, i, j+1, visited, m, n);
            if(i-1>=0 && j-1>=0) dfs(board, i-1, j-1, visited, m, n);
            if(i-1>=0 && j+1<n)  dfs(board, i-1, j+1, visited, m, n);
            if(i+1<m && j-1>=0)  dfs(board, i+1, j-1, visited, m, n);
            if(i+1<m && j+1<n)   dfs(board, i+1, j+1, visited, m, n);
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        if(board[click[0]][click[1]] == 'E'){
            dfs(board, click[0], click[1], visited, m, n);
        }
        return board;
    }
};
