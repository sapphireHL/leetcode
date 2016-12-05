class Solution {
public:
    string convert(string s){
        string res = s;
        map<char, vector<int>> tables;
        int counts = 0;
        for(int i=0; i<s.length(); i++){
            if(tables[s[i]].size() == 0){
                tables[s[i]].push_back(counts++);
            }
            tables[s[i]].push_back(i);
        }
        map<char, vector<int>>::iterator it = tables.begin();
        while(it != tables.end()){
            for(int i=1; i<it->second.size(); i++){
                res[it->second[i]] = it->second[0] + 48;
            }
            it++;
        }
        return res;
    }
    bool isIsomorphic(string s, string t) {
        return !strcmp(convert(s).c_str(), convert(t).c_str());
    }
};
