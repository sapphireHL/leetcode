class Solution {
public:
    int flipLights(int n, int m) {
        if(m == 0) return 1;
        if(n == 1) return 2;
        if(n == 2 && m == 1) return 3;
        if(n == 2 && m > 1) return 4;
        if(n >= 3 && m == 1) return 4;
        if(n >= 3 && m == 2) return 7;
        if(n >= 3 && m >= 3) return 8;
    }
};
