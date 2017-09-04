class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty()) return vector<int>(0);
        unordered_map<string, int> wordDict;
        for(int i=0; i<words.size(); i++) wordDict[words[i]]++;
        vector<int> res;
        const int len = words[0].size(), n = words.size();
        if(s.size() < len*n) return vector<int>(0);
        for(int i=0; i<=s.size()-len*n; i++){
            int start = i;
            unordered_map<string, int> appear;
            for(int j=0; j<n; j++){
                string curword = s.substr(start, len);
                if(wordDict.find(curword) != wordDict.end()){
                    appear[curword]++;
                    if(appear[curword] > wordDict[curword]) break;
                }
                start += len;
            }
            if(appear == wordDict) res.push_back(i);
        }
        return res;
    }
};
