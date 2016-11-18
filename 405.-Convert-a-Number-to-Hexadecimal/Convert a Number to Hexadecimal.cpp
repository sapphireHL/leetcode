class Solution {
public:
    string toHex(int num) {
        if(num==0){
            return "0";
        }
        string res;
        string hex = "0123456789abcdef";
        int remain = 0;
        long int lnum = num;
        if(lnum < 0){
            lnum += pow(16, 8);
        }
        while(lnum > 0){
            remain = lnum % 16;
            lnum /= 16;
            res += hex[remain];
        }
        for(int i=0; i<res.size()/2; i++){
            char temp = res[i];
            res[i] = res[res.size()-1-i];
            res[res.size()-1-i] = temp;
        }
        return res;
    }
};
