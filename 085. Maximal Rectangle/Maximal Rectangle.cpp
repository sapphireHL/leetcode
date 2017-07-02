class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    
    //DP equation:
    //res = [right(i,j) - left(i,j)]*height(i,j).
    //left(i,j) = max(left(i-1,j), cur_left), cur_left can be determined from the current row
    //right(i,j) = min(right(i-1,j), cur_right), cur_right can be determined from the current row
    //height(i,j) = height(i-1,j) + 1, if matrix[i][j]=='1';
    //height(i,j) = 0, if matrix[i][j]=='0'
 
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
                res = max(res, (right[j]-left[j])*height[j]);
            }
        }
        return res;
    }
};
