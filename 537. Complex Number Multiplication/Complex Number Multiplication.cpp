class Solution {
public:
    void getnumbers(string s, int nums[]){
        int pluspos = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '+'){
                nums[0] = atoi(s.substr(0, i).c_str());
                pluspos = i;
            }
            if(s[i] == 'i'){
                nums[1] = atoi(s.substr(pluspos+1, i-pluspos-1).c_str());
            }
        }
    }
    string complexNumberMultiply(string a, string b) {
        string result;
        int anum[2] = {0}, bnum[2] = {0}, i = 0;
        getnumbers(a, anum);
        getnumbers(b, bnum);
        result += to_string(anum[0]*bnum[0] - anum[1]*bnum[1]);
        result += '+';
        result += to_string(anum[0]*bnum[1] + anum[1]*bnum[0]);
        result += 'i';
        return result;
    }
};
