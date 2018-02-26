class Solution {
public:
    bool check(int n){
        int level1 = 0;
        while(n != 0){
            int tmp = n % 10;
            if(tmp == 3 || tmp == 4 || tmp == 7)
                return false;
            if(tmp == 2 || tmp == 5 || tmp == 6 || tmp == 9)
                level1 = 1;
            n /= 10;
        }
        return level1;
    }
    int rotatedDigits(int N) {
        int res = 0;
        for(int i = 1; i <= N; i++){
            if(check(i)) res++;
        }
        return res;
    }
};
