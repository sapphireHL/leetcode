class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int d = 1, y=x;
        while(x>=10) {
            x/=10;
            d*=10;
        }
        while(d!=0){
            if(y%10 != y/d) return false;
            y = y%d/10;
            d/=100;
        }
        return true;
    }
};
