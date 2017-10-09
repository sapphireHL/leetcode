class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n % 2;
        n /= 2;
        while(n != 0){
            int cur = n % 2;
            n /= 2;
            if(last == cur) return false;
            last = cur;
        }
        return true;
    }
};
