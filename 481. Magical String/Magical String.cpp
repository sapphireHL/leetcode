class Solution {
public:
    int magicalString(int n) {
        if(n == 0) 
            return 0;
        int result = 1;
        string init = "122";
        int type[2] = {1,2};
        for(int i=2; i<n; i++){
            for(int j=0; j<init[i]-'0'; j++)
                init += '0'+type[i%2];
            if(init[i] == '1')
                result++;
        }
        return result;
    }
};
