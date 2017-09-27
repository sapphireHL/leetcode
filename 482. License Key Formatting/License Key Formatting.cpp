class Solution {
public:
    void convertUpper(string& s){
        for(int i=0; i<s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] += 'A'-'a';
        }
    }
    string licenseKeyFormatting(string S, int K) {
        stringstream ss(S);
        string tmp, pure;
        while(getline(ss, tmp, '-')){
            if(tmp != "") pure += tmp;
        }
        convertUpper(pure);
        int first = K;
        if(pure.size() % K != 0) first = pure.size() % K;
        string res;
        int i=0;
        while(i<pure.size()){
            if(i == 0){
                for(int j=0; j<first; j++,i++) res += pure[i];
                res += '-';
            }
            else{
                for(int j=0; j<K; j++,i++) res += pure[i];
                res += '-';
            }
        }
        res.pop_back();
        return res;
    }
};
