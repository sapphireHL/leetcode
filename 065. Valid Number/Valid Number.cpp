class Solution {
public:
    bool isNumber(string s) {
        int countdot = 0, counte = 0, countnum = 0, i = 0;
        
        // skip the whilespaces
        while(s[i] == ' ') i++;
        
        // check the significand
        if(s[i] == '-' || s[i] == '+') i++;
        
        int n_nm, n_pt;
        for(n_nm=0, n_pt=0; (s[i]<='9' && s[i]>='0') || s[i]=='.'; i++)
            s[i] == '.' ? n_pt++:n_nm++;       
        if(n_pt>1 || n_nm<1) // no more than one point, at least one digit
            return false;
          
        // check the exponent if exist
        if(s[i] == 'e') {
            i++;
            if(s[i] == '+' || s[i] == '-') i++; // skip the sign
            
            int n_nm = 0;
            for(; s[i]>='0' && s[i]<='9'; i++, n_nm++) {}
            if(n_nm<1)
                return false;
        }
        for(; s[i] == ' '; i++) {}
        return s[i] == 0;
    }
};
