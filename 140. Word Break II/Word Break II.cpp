class Solution {
public:
    unordered_map<string, vector<string>> m;
    
    vector<string> combine(string cur, vector<string> pre){
        for(int i=0; i<pre.size(); i++){
            pre[i] += " "+cur;
        }
        return pre;
    }
    
    vector<string> wordBreak2(string s, unordered_set<string>& dict){
        if(m.count(s)) return m[s];
        vector<string> res;
        if(dict.count(s)){
            res.push_back(s);
        }
        for(int i=1; i<s.size(); i++){
            string cur = s.substr(i);
            if(dict.count(cur)){
                string prev = s.substr(0, i);
                vector<string> so = combine(cur, wordBreak2(prev, dict));
                res.insert(res.end(), so.begin(), so.end());
            }
        }
        m[s] = res;
        return res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreak2(s, dict);
    }
};
