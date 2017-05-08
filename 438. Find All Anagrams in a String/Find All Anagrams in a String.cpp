class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result, sv(26), pv(26);
        const int psize = p.size(), ssize = s.size();
        //sliding window
        for(int i=0; i<psize; i++) {
            pv[p[i]-'a']++;
            sv[s[i]-'a']++;
        }
        if(sv == pv) result.push_back(0);
        for(int i=psize; i<ssize; i++){
            sv[s[i]-'a']++;
            sv[s[i-psize]-'a']--;
            if(sv == pv) result.push_back(i-psize+1);
        }
        return result;
    }
};
