class Solution {
public:
    void dfs(vector<string>&res, string p, vector<string> keyboard, int cur, string digits){
        if(cur == digits.size()) {
            res.push_back(p);
            return;
        }
        for(auto i:keyboard[digits[cur]-'0']){
            dfs(res, p+i, keyboard, cur+1, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits == "") return res;
        vector<string> keyboard {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string p;
        dfs(res, p, keyboard, 0, digits);
        return res;
    }
};
