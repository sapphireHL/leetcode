class Solution {
public:
    long c(int a, int b){
        long res = 1;
        int count = b;
        for(int i=0; i<b; i++){
            res *= (a-i);
            if(count >= 1 && res % count == 0){
                res /= count;
                count--;
            }
        }
        while(count >= 1){
            res /= count--;
        }
        return res;
    }
    int uniquePaths(int m, int n) {
        int res = 0;
        int total = m-1+n-1;
        res = c(total, max(m-1, n-1));
        return res;
    }
};
