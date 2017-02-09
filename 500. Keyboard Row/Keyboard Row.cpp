class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        int basea = (int)'A';
        int length = (int)'z'-(int)'A'+1;
        vector<int>table(length, 0);
        table['Q'-basea]=table['q'-basea]=1;
        table['W'-basea]=table['w'-basea]=1;
        table['E'-basea]=table['e'-basea]=1;
        table['R'-basea]=table['r'-basea]=1;
        table['T'-basea]=table['t'-basea]=1;
        table['Y'-basea]=table['y'-basea]=1;
        table['U'-basea]=table['u'-basea]=1;
        table['I'-basea]=table['i'-basea]=1;
        table['O'-basea]=table['o'-basea]=1;
        table['P'-basea]=table['p'-basea]=1;
        
        table['A'-basea]=table['a'-basea]=2;
        table['S'-basea]=table['s'-basea]=2;
        table['D'-basea]=table['d'-basea]=2;
        table['F'-basea]=table['f'-basea]=2;
        table['G'-basea]=table['g'-basea]=2;
        table['H'-basea]=table['h'-basea]=2;
        table['J'-basea]=table['j'-basea]=2;
        table['K'-basea]=table['k'-basea]=2;
        table['L'-basea]=table['l'-basea]=2;
        
        table['Z'-basea]=table['z'-basea]=3;
        table['X'-basea]=table['x'-basea]=3;
        table['C'-basea]=table['c'-basea]=3;
        table['V'-basea]=table['v'-basea]=3;
        table['B'-basea]=table['b'-basea]=3;
        table['N'-basea]=table['n'-basea]=3;
        table['M'-basea]=table['m'-basea]=3;
        
        for(int i=0; i<words.size(); i++){
            int basech = words[i][0];
            bool issame = 1;
            for(int j=1; j<words[i].length(); j++){
                int currentch = words[i][j];
                if(table[currentch-basea] != table[basech-basea]){
                    issame = 0;
                    break;
                }
            }
            if(issame){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};
