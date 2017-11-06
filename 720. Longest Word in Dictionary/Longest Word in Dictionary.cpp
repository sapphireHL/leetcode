class Solution {
public:
    bool cmp(const string& a, const string& b){
        if(a.size() != b.size())
            return a.size() > b.size();
        else{
            for(int i=0; i<a.size(); i++){
                if(a[i] == b[i])
                    continue;
                else
                    return a[i] < b[i];
            }
        }
    }
    string longestWord(vector<string>& words) {
        string res;
        unordered_set<string> s(words.begin(), words.end());
        for(int i=0; i<words.size(); i++){
            string tmp = words[i];
            bool flag = true;
            while(!tmp.empty()){
                if(!s.count(tmp)){
                    flag = false;
                    break;
                }
                tmp.pop_back();
            }
            if(flag){
                if(cmp(words[i], res))
                    res = words[i];
            }
        }
        return res;
    }
};
