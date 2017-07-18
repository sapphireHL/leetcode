class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string tmp;
        int res=0;
        while(getline(ss, tmp, ' ')){
            if(tmp=="") continue;
            else res++; 
        }
        return res;
    }
};
