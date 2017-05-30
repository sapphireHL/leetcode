class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> m, m2;
        int n1 = list1.size(), n2 = list2.size(), min = INT_MAX;
        for(int i=0; i<n1; i++){
            m[list1[i]] = i+1;
        }
        for(int i=0; i<n2; i++){
            if(m[list2[i]] != 0){
                m2[list2[i]] = m[list2[i]]+i+1;
                if(min > m2[list2[i]]) min = m2[list2[i]];
            }
        }
        if(min == INT_MAX) return res;
        for(auto i:m2){
            if(i.second == min) res.push_back(i.first);
        }
        return res;
    }
};
