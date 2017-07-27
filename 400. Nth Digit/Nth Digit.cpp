class Solution {
public:
    int findNthDigit(int n) {
        long long table[10] = {9,90,900,9000,90000,900000,9000000,90000000,900000000,9000000000};
        int i=0;
        while(n > (i+1)*table[i]){
            n -= (i+1)*table[i];
            i++;
        }
        int base = pow(10,i);
        int curnum = (n-1) / (i+1)+base, bit = (n-1) %(i+1);
       //cout<<curnum<<' '<<bit<<endl;
        while(bit>0){
            curnum %= base;
            bit--;
            base /= 10;;
        }
        return curnum / base;
    }
};
