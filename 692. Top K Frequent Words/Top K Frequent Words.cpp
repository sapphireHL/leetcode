class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> f;
        map<int, vector<string>> f_reverse;
        vector<string> res;
        for(auto w:words) {
            f[w]++;
        }
        for(auto i:f){
            f_reverse[i.second].push_back(i.first);
        }
        int count = 0;
        for(auto i=f_reverse.rbegin(); i!=f_reverse.rend(); i++){
            for(int j=0; j<i->second.size(); j++){
                res.push_back(i->second[j]);
                count++;
                if(count == k) return res;
            }
        }
        return res;
    }
};
