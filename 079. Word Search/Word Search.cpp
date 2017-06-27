class Solution {
public:
    bool flag = false;
    void dfs(vector<vector<char>>& board, string word, vector<vector<int>> &visited, int i, int j, int current){
        if(flag) return;
        if(current == word.size()) {flag=true;return;};
        if(i<0 || i>=board.size() || j<0 || j>= board[0].size()) return;
        if(visited[i][j]) return;
        if(board[i][j] != word[current]) return;
        
        else{
            visited[i][j] = 1;
            dfs(board, word, visited, i-1, j, current+1); 
            dfs(board, word, visited, i+1, j, current+1); 
            dfs(board, word, visited, i, j-1, current+1); 
            dfs(board, word, visited, i, j+1, current+1);
            visited[i][j] = 0;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]) {
                    dfs(board, word, visited, i, j, 0);
                }
            }
        }
        return flag;
    }
};
