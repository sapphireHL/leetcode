class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> group;
        for(auto i:strs){
            string key = i;
            sort(key.begin(), key.end());
            group[key].push_back(i);
        }
        for(auto i=group.begin(); i!=group.end(); i++){
            result.push_back(i->second);
        }
        return result;
    }
};
