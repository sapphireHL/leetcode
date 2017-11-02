class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        for(; i<bits.size(); ){
            if(i == bits.size() - 1) return true;
            if(bits[i] == 1) i += 2;
            else i++;
        }
        return false;
    }
};
