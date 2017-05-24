class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        if(matrix[0].size() == 0) return false;
        int n=matrix.size(), m=matrix[0].size();
        int start = 0, end = n*m-1;
        
        while(start <= end){
            int mid = start+(end-start)/2;
            if(matrix[mid/m][mid%m] > target){
                end = mid-1;
            }
            else if(matrix[mid/m][mid%m] < target){
                start = mid+1;
            }
            else return true;
        }
        return false;
    }
};
