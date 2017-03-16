class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0) 
            return result;
        for(int i=0; i<matrix.size()+matrix[0].size()-1; i++){
            if(i%2 == 0){
                for(int j=matrix.size()-1; j>=0; j--){
                    if(i-j < 0 || i-j >= matrix[0].size())
                        continue;
                    else{
                        result.push_back(matrix[j][i-j]);
                    }
                }
            }
            else{
                for(int j=0; j<matrix.size(); j++){
                    if(i-j < 0 || i-j >= matrix[0].size())
                        continue;
                    else{
                        result.push_back(matrix[j][i-j]);
                    }
                }
            }
        }
        return result;
    }
};
