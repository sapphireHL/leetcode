class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int res = 0;
        vector<int> height(n,0), left(n,0), right(n,n);
        for(int i=0; i<m; i++){
            int curleft = 0, curright = n;
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    left[j] = max(left[j], curleft);
                    height[j]++;
                }
                else{
                    left[j]=0;
                    curleft = j+1;
                    height[j]=0;
                }
            }
            for(int j=n-1; j>=0; j--){
                if(matrix[i][j] == '1'){
                    right[j] = min(right[j], curright);
                }
                else{
                    right[j] = n;
                    curright = j;
                }
                int squre = min(height[j], right[j]-left[j]);
                    res = max(res, squre*squre);
            }
        }
        return res;
    }
};
