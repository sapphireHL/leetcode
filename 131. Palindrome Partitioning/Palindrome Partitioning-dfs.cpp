class Solution {
public:
    bool ispalindrome(string s, int start, int end){
        while(start < end && s[start] == s[end]) {
            start++;
            end--;
        }
        return start >= end;
    }
    void dfs(string s, vector<string>&path, vector<vector<string>> &res, int start){
        if(start == s.size()){
            res.push_back(path);
            return;
        }
        for(int i=start; i<s.size(); i++){
            if(ispalindrome(s, start, i)){
                path.push_back(s.substr(start, i-start+1));
                dfs(s, path, res, i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, path, res, 0);
        return res;
    }
};
