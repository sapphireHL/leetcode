class Solution {
public:
    int climbStairs(int n) {
        // if(n == 0) return 0;
        // if(n == 1) return 1;
        // if(n == 2) return 2;
        // int n1 = 1;
        // int n2 = 2;
        // int all = 0;
        // for (int i=3; i<=n; i++)
        // {
        //     all = n1+n2;
        //     n1 = n2;
        //     n2 = all;
        // }
        // return all;
        
        
        
        //fibonacci
        double s = sqrt(5);
        return (pow((1+s)/2, n+1)-pow((1-s)/2, n+1)) / s;
    }
};
