class Solution {
public:
    unordered_map<string, vector<char>> mp;
    bool flag;
    
    void dfs(string curbottom, string &next, int curpos){
        if(flag) return;
        if(curbottom.size() == 1){
            flag = true;   
            return;
        }
        if(curpos == curbottom.size()-1){
            string s;
            dfs(next, s, 0);
        }
        
        for(int i = curpos; i < curbottom.size() - 1; i++){
            string pair = curbottom.substr(i, 2);
            if(!mp.count(pair)) return;
            for(int j = 0; j < mp[pair].size(); j++){
                next += mp[pair][j];
                dfs(curbottom, next, curpos + 1);
                next.pop_back();
            }
        }
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(string s:allowed){
            mp[s.substr(0,2)].push_back(s[2]);
        }
        string next;
        dfs(bottom, next, 0);
        return flag;
    }
};
