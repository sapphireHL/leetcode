class Solution {
public:
    bool isPerfectSquare(int num) {
        return (int)sqrt(num) == sqrt(num);
    }
    bool judgeSquareSum(int c) {
        int end = sqrt(c);
        for(int i=0; i<=end; i++){
            if(isPerfectSquare(i*i) && isPerfectSquare(c-i*i)) return true;
        }
        return false;
    }
};
