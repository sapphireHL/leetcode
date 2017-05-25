class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int i=0; i<12; i++){
            for(int j=0; j<60; j++){
                bitset<10> t(i<<6 | j);
                if(num == t.count()) res.push_back(to_string(i)+(j<10?":0":":")+to_string(j));
            }
        }
        return res;
    }
};
