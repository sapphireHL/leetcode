class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        bool is_first_i_zero = 0, is_first_j_zero = 0;
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0] == 0){
                is_first_j_zero = 1;
                break;
            }
        }
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[0][j] == 0){
                is_first_i_zero = 1;
                break;
            }
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(is_first_i_zero)
            for(int i=0; i<matrix[0].size(); i++)
                matrix[0][i] = 0;
        if(is_first_j_zero)
            for(int i=0; i<matrix.size(); i++)
                matrix[i][0] = 0;
        
    }
};
