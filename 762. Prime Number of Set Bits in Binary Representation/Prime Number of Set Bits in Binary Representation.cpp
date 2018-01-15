class Solution {
public:
    const int n = 1000005;
    
    bool isPrim(int n){
        if(n <= 1) return false;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
    
    int countPrimeSetBits(int L, int R) {
        static vector<int> sets;
        
        if(sets.empty()){
            sets.push_back(0);
            while(sets.size() < n){
                int size = sets.size();
                for(int i = 0; i < size; i++){
                    sets.push_back(sets[i] + 1);
                    if(sets.size() > n)
                        break;
                }
            }
        }
        
        int res = 0;
        for(int i = L; i <= R; i++){
            if(isPrim(sets[i]))
                res++;
        }
        return res;
    }
};
