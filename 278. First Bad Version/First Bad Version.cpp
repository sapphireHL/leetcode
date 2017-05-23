// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=0, right = n, mid=0;
        while(left < right){
            ///////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //(left+right)/2 可能会溢出！！！！！！
            mid = left+(right-left)/2;
            if(isBadVersion(mid)){
                if(mid == 1 || !isBadVersion(mid-1)) return mid;
                else right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return left;
    }
};
