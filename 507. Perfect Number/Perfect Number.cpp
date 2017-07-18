class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1||num==0) return false;
        int res = 0;
        for(int i=1; i<=sqrt(num); i++){
            if(num%i==0) res+=i+num/i;
        }
        return 2*num==res;
    }
};
