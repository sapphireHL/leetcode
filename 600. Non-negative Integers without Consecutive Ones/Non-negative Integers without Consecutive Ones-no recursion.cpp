class Solution {
public:
    int findIntegers(int num) {
        if(num <= 2) return num+1;
        int res = 0;
        vector<int> fib(32);
        fib[0]=1;
        fib[1]=2;
        for(int i=2; i<32; i++) fib[i] = fib[i-1]+fib[i-2];
        int k = 31, prebit = 0;
        while(k>=0){
            if(num &(1<<k)){
                res += fib[k];
                if(prebit) return res;
                prebit = 1;
            }
            else
                prebit = 0;
            k--;
        }
        return res+1;
    }
};
