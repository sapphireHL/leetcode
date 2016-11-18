class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gcount = 0;
        for(int i=0; i<s.size()&&gcount<g.size(); i++){
            if(s[i] >= g[gcount]){
                res++;
                gcount++;
            }
        }
        return res;
    }
};
