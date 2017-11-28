class Solution {
public:
    unordered_map<string, string> parent;
    string find(string x){
        if(!parent.count(x)) return x;
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        const int m = words1.size(), n = words2.size();
        if(m != n) return false;
        //init
        for(auto i:pairs){
            parent[i.first] = i.first;
            parent[i.second] = i.second;
        }
        //union
        for(auto i:pairs){
            string pa = find(i.first), pb = find(i.second);
            if(pa != pb)
                parent[pa] = pb;
        }
        for(int i=0; i<m; i++){
            string pa = find(words1[i]), pb = find(words2[i]);
            if(pa != pb) return false;
        }
        return true;
    }
};
