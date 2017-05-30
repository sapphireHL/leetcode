class Solution {
public:
    int helper(int num, vector<int> fib){
        int n = 0;
        for(int tmp = num; tmp; tmp/=2, n++){}
        if(num >= (1<<n-1) + (1<<n-2)) return fib[n];
        else return fib[n-1]+helper(num - (1<<n-1), fib);
    }
    int findIntegers(int num) {
        if(num <= 2) return num+1;
        int res = 0;
        vector<int> fib(32);
        fib[0]=1;
        fib[1]=2;
        for(int i=2; i<32; i++) fib[i] = fib[i-1]+fib[i-2];
        res = helper(num, fib);
        return res;
    }
};
