class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        const int m = matrix.size(), n = matrix[0].size();
        res.resize(m*n);
        int i = 0, j = 0;
        int bound_R = n - 1, bound_D = m - 1, bound_L = 0, bound_U = 1;
        int count = 0;
        while (count < m*n){
            for (; j <= bound_R && count<m*n; j++) 
                res[count++] = matrix[i][j];
            j--;
            i++;
            bound_R--;
            for (; i <= bound_D && count<m*n; i++) 
                res[count++] = matrix[i][j];
            i--;
            j--;
            bound_D--;
            for (; j >= bound_L && count<m*n; j--) 
                res[count++] = matrix[i][j];
            j++;
            i--;
            bound_L++;
            for (; i >= bound_U && count<m*n; i--) 
                res[count++] = matrix[i][j];
            i++;
            j++;
            bound_U++;
        }
        return res;
    }
};
