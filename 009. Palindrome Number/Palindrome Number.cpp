class Solution {
public:
    int reverse(int x){
        long res = 0;
        while(x!=0){
            res = res*10+x%10;
            x/=10;
        }
        if(x>=INT_MAX || x<=INT_MIN) return 0;
        return res;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        int y = reverse(x);
        return x==y;
    }
};
