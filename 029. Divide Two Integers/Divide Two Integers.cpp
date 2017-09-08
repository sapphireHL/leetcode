class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend>=0?dividend:-(long long)(dividend);
        long long b = divisor>=0?divisor:-(long long)(divisor);
        long long res = 0;
        int sign = (dividend>0&&divisor>0)||(dividend<0&&divisor<0)?1:-1;
        while(a >= b){
            long long c = b;
            for(int i=0; a >= c; c<<=1, i++){
                a -= c;
                res += 1<<i;
            }
        }
        long long res2 = res*sign;
        if(res2 > INT_MAX || res2 < INT_MIN) return INT_MAX;
        return res*sign;
    }
};
