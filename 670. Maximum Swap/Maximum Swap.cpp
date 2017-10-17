class Solution {
public:
    int res;

    int maximumSwap(int num) {
        res = num;
        string bit = to_string(num);
        for(int i=0; i<bit.size(); i++){
            for(int j=i+1; j<bit.size(); j++){
                swap(bit[i], bit[j]);
                res = max(res, stoi(bit));
                swap(bit[i], bit[j]);
            }
        }
        return res;
    }
};
