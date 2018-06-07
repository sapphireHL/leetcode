class Solution {
public:
    string tran[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                         "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
                         "...-",".--","-..-","-.--","--.."};
    
    string code(const string& s){
        string res;
        for(int i=0; i<s.size(); ++i){
            res += tran[s[i]-'a'];
        }
        return res;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> tb;
        
        for(string s : words){
            string res = code(s);
            tb.insert(res);
        }
        return tb.size();
    }
};
