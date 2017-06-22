class Solution {
public:
    void dfs(string s, vector<string>& res, vector<string>& path, int start){
        if(path.size() == 4 && start == s.size()){
            string tmp = path[0]+'.'+path[1]+'.'+path[2]+'.'+path[3];
            res.push_back(tmp);
            return;
        }
        if(s.size() - start > (4-path.size())*3) return;
        if(s.size() -start < 4-path.size()) return;
        
        int num = 0;
        for(int i=start; i<start+3; i++){
            num = num*10 + s[i]-'0';
            if(num <= 255){
                path.push_back(to_string(num));
                dfs(s, res, path, i+1);
                path.pop_back();
            }
            if(num == 0) break;//前缀不能有0，可以有单个0
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res, path;
        dfs(s, res, path, 0);
        return res;
    }
};
