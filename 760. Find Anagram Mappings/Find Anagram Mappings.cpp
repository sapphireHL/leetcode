class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i=0; i<B.size(); i++){
            mp[B[i]] = i;
        }
        for(int i=0; i<A.size(); i++){
            auto it = mp.find(A[i]);
            res.push_back(it->second);
        }
        return res;
    }
};
