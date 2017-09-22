class Solution {
public:
    static bool cmp(string a, string b){
        if(a == b) return a == b;
        if(a.size() == b.size()){
            for(int i=0; i<a.size(); i++){
                if(a[i] != b[i])
                    return a[i] < b[i];
            }
        }
        else return a.size() > b.size();
    }
    
    bool issub(string s, string d){
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == d[count]){
                count++;
            }
        }
        return count == d.size();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), cmp);
        for(int i=0; i<d.size(); i++){
            if(issub(s, d[i])) return d[i];
        }
        return "";
    }
};
