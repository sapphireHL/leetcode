class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> res;
        for(int i = 0; i <= (int)s.size() - 10; i++){
            string sub = s.substr(i, 10);
            mp[sub]++;
        }
        for(auto it:mp){
            if(it.second >= 2){
                res.push_back(it.first);
            }
        }
        return res;
    }
};
