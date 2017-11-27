class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        const int m = words1.size(), n = words2.size();
        if(m != n) return false;
        unordered_map<string, unordered_set<string>> list;
        for(int i=0; i<pairs.size(); i++){
            list[pairs[i].first].insert(pairs[i].second);
            list[pairs[i].second].insert(pairs[i].first);
        }
        for(int i=0; i<m; i++){
            if(words1[i] == words2[i] || list[words1[i]].count(words2[i]) || list[words2[i]].count(words1[i]))
                continue;
            else
                return false;
        }
        return true;
    }
};
