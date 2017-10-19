class Solution {
public:

    int countPrimes(int n) {
        vector<int> isprime;
        isprime.resize(n);
        for(int i = 2; i * i < n; i++)
        {
            if(isprime[i] == 1)
                continue;
            for(int j = i * i; j < n; j += i)
                isprime[j] = 1;
        }
        int res = 0;
        for(int i = 2; i < n; i++)
        {
            if(isprime[i] == 0)
                res++;
        }
        return res;
    }
};
