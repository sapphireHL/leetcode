class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        long long left = 1, right = (num+1)/2;
        while(left < right){
            if(right-left==1 && left*left!=num && right*right!=num) return false;
            long long mid = left+(right-left+1)/2;
            if(mid*mid < num) left = mid;
            else if(mid*mid > num) right = mid;
            else return true;
        }
        return false;
    }
};
