class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        if(matrix[0].empty()) return false;
        int n=matrix.size(), m=matrix[0].size(), i=0, j=m-1;
        while(i<n && j>=0){
            if(matrix[i][j] < target) i++;
            else if(matrix[i][j] > target) j--;
            else return true;
        }
        return false;
    }
};
