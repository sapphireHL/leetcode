class Solution {
public:
    bool isprime[1001];
    void prime(){
        for(int i=0; i<=1000; i++) isprime[i] =  true;
        for(int i = 2; i < sqrt(1000); i++){
            if(!isprime[i]) continue;
            for(int j = i+i; j < 1001; j+=i){
                if(isprime[j])
                    isprime[j] = false;
            }
        }
    }
    int minSteps(int n) {
        vector<int> dp(n+1);
        prime();
        for(int i=2; i<=n; i++){
            if(isprime[i])//如果这个数是质数，次数等于它本身
                dp[i] = i;
            else{//若不是质数，则次数等于他的两个因数的次数之和
                for(int j=2; j<=sqrt(i); j++){
                    if(i%j == 0){
                        dp[i] = dp[i/j]+dp[j];
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
