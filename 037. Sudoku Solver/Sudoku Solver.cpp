class Solution {
public:
	bool check(vector<vector<char>>& board, int i, int j, char ch){
		for (int ii = 0; ii<9; ii++){
			if (ii != i && ch == board[ii][j]) return false;
		}
		for (int jj = 0; jj<9; jj++){
			if (jj != j && ch == board[i][jj]) return false;
		}
		for (int ii = i / 3 * 3; ii<i / 3 * 3 + 3; ii++){
			for (int jj = j / 3 * 3; jj<j / 3 * 3 + 3; jj++){
				if (ii != i && jj != j && ch == board[ii][jj]) return false;
			}
		}
		return true;
	}
	bool dfs(vector<vector<char>>& board, int pos){
		if (pos == 81) return true;
		int i = pos / 9, j = pos % 9;
		if (board[i][j] != '.') return dfs(board, pos + 1);
		else{
			for (int k = 1; k <= 9; k++){
				board[i][j] = k + '0';
				if (check(board, i, j, board[i][j])){
					if (dfs(board, pos + 1)) return true;
				}
				board[i][j] = '.';
			}
		}
		return false;
	}
	void solveSudoku(vector<vector<char>>& board) {
		dfs(board, 0);
	}
};
