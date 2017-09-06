class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if(n == 0) return res;
        res.resize(n, vector<int>(n));
        int count = 1;
        int i = 0, j = 0;
        int bound_R = n - 1, bound_D = n - 1, bound_L = 0, bound_U = 1;
        while(count <= n*n){
            for (; j <= bound_R && count<=n*n; j++) 
                res[i][j] = count++;
            j--;
            i++;
            bound_R--;
            for (; i <= bound_D && count<=n*n; i++) 
                res[i][j] = count++;
            i--;
            j--;
            bound_D--;
            for (; j >= bound_L && count<=n*n; j--) 
                res[i][j] = count++;
            j++;
            i--;
            bound_L++;
            for (; i >= bound_U && count<=n*n; i--) 
                res[i][j] = count++;
            i++;
            j++;
            bound_U++;
        }
        return res;
    }
};
