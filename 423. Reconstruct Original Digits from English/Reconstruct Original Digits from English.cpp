class Solution {
public:
    string originalDigits(string s) {
        string res;
        vector<int> v(26, 0);
        vector<int> digit(10, 0);
        for(int i=0; i<s.length(); i++){
            v[s[i]-97]++;
        }
        if(v['z'-97] != 0){
            v['e'-97] -= v['z'-97];
            v['r'-97] -= v['z'-97];
            v['o'-97] -= v['z'-97];
            digit[0] += v['z'-97];
            v['z'-97] = 0;
        }
        if(v['w'-97] != 0){
            v['t'-97] -= v['w'-97];
            v['o'-97] -= v['w'-97];
            digit[2] += v['w'-97];
            v['w'-97] = 0;
        }
        if(v['u'-97] != 0){
            v['f'-97] -= v['u'-97];
            v['o'-97] -= v['u'-97];
            v['r'-97] -= v['u'-97];
            digit[4] += v['u'-97];
            v['u'-97] = 0;
        }
        if(v['x'-97] != 0){
            v['s'-97] -= v['x'-97];
            v['i'-97] -= v['x'-97];
            digit[6] += v['x'-97];
            v['x'-97] = 0;
        }
        if(v['g'-97] != 0){
            v['e'-97] -= v['g'-97];
            v['i'-97] -= v['g'-97];
            v['h'-97] -= v['g'-97];
            v['t'-97] -= v['g'-97];
            digit[8] += v['g'-97];
            v['g'-97] = 0;
        }
        if(v['o'-97] != 0){
            v['n'-97] -= v['o'-97];
            v['e'-97] -= v['o'-97];
            digit[1] += v['o'-97];
            v['o'-97] = 0;
        }
        if(v['t'-97] != 0){
            v['h'-97] -= v['t'-97];
            v['r'-97] -= v['t'-97];
            v['e'-97] -= v['t'-97]*2;
            digit[3] += v['t'-97];
            v['t'-97] = 0;
        }
        if(v['f'-97] != 0){
            v['i'-97] -= v['f'-97];
            v['v'-97] -= v['f'-97];
            v['e'-97] -= v['f'-97];
            digit[5] += v['f'-97];
            v['f'-97] = 0;
        }
        if(v['s'-97] != 0){
            v['e'-97] -= v['s'-97]*2;
            v['v'-97] -= v['s'-97];
            v['n'-97] -= v['s'-97];
            digit[7] += v['s'-97];
            v['s'-97] = 0;
        }
        digit[9] += v['i'-97];
        
        for(int i=0; i<10; i++){
            for(int j=0; j<digit[i]; j++){
                res += i + 48;
            }
        }
        return res;
    }
};
