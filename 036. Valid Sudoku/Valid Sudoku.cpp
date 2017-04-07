class Solution {
public:
    bool isvalid(char s, vector<int> &table)
    {
        if(s != '.'){
            if(table[s-'1'] >= 1)
                return false;
             table[s-'1']++;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            vector<int> table(9, 0);
            for(int j=0; j<9; j++){
                if(!isvalid(board[i][j], table)) return false;
            }
        }
        for(int j=0; j<9; j++){
            vector<int> table(9, 0);
            for(int i=0; i<9; i++){
                if(!isvalid(board[i][j], table)) return false;
            }
        }
        for(int k=0; k<9; k++){
            vector<int> table(9, 0);
            for(int i=3*(k%3); i<3*(k%3)+3; i++){
                for(int j=3*(k/3); j<3*(k/3)+3; j++){
                    if(!isvalid(board[i][j], table)) return false;
                }
            }
        }
        return true;
    }
};
