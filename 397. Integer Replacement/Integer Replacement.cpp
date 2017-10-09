class Solution {
public:
    int integerReplacement(int n) {
        int step = 0;
        //2147483647会溢出
        long long n2 = n;
        while(n2 != 1){
            if(n2 % 2 == 0)
                n2 /= 2;
            else if(n2 == 3 || (n2 & 2) == 0)
                n2--;
            else
                n2++;
            step++;
        }
        return step;
    }
};
