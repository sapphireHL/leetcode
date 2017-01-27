class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int table[32] = {0};
        for(int i=1; i<=32; i++){
            table[i-1] = pow(2, i) - 1;
        }
        int i = 0;
        while(i<32){
            if(num <= table[i]){
                return table[i] - num;
            }
            i++;
        }
    }
};
