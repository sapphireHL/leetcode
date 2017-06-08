class Solution {
public:
    void add2(vector<int> a, vector<int> b, unordered_map<int, int>& m){
        for(int i:a){
            for(int j:b){
                m[i+j]++;
            }
        }
    }
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> m1, m2;
        add2(A, B, m1);
        add2(C, D, m2);
        for(auto i:m1){
            auto j = m2.find(-i.first);
            if(j != m2.end()){
                res += i.second*j->second;
            }
        }
        return res;
    }
};
