class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> s;
        unordered_map<char, string> m;
        unordered_map<string, char> m_reverse;
        stringstream ss(str);
        string tmp;
        while(getline(ss, tmp, ' ')) s.push_back(tmp);
        if(pattern.size() != s.size()) return false;
        for(int i=0; i<pattern.size(); i++){
            if(m.find(pattern[i]) == m.end()){
                if(m_reverse.find(s[i]) != m_reverse.end() && m_reverse[s[i]] != pattern[i]) return false;
                m[pattern[i]] = s[i];
                m_reverse[s[i]] = pattern[i];
            } 
            else {
                if(m[pattern[i]] != s[i]) return false;
            }
        }
        return true;
    }
};
