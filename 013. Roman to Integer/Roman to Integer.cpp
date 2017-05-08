class Solution {
public:
    int romanToInt(string s) {
        string I[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string X[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string C[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string M[]={"","M","MM","MMM"};
        int pos = 0,result = 0;
        for(int i=3; i>=0; i--){
            if(s.substr(pos, M[i].size()) == M[i]){
                pos += M[i].size();
                result += 1000*i;
                break;
            }
        }
        for(int i=9; i>=0; i--){
            if(s.substr(pos, C[i].size()) == C[i]){
                pos += C[i].size();
                result += 100*i;
                break;
            }
        }
        for(int i=9; i>=0; i--){
            if(s.substr(pos, X[i].size()) == X[i]){
                pos += X[i].size();
                result += 10*i;
                break;
            }
        }
        for(int i=9; i>=0; i--){
            if(s.substr(pos, I[i].size()) == I[i]){
                pos += I[i].size();
                result += i;
                break;
            }
        }
        return result;
    }
};
