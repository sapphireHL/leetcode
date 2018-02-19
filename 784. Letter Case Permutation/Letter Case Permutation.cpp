class Solution {
public:
    vector<string> res;
    
    void dfs(string& s, int cur){
        res.push_back(s);
        for(int i = cur; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] += 'A'-'a';
                dfs(s, i+1);
                s[i] -= 'A'-'a';
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] += 'a'-'A';
                dfs(s, i+1);
                s[i] -= 'a'-'A';
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        dfs(S, 0);
        return res;
    }
};
