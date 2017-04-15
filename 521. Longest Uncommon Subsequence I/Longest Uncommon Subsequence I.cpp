class Solution {
public:
    int findLUSlength(string a, string b) {
        int result = 0;
        if(a.size() != b.size())
            return max(a.size(), b.size());
        bool same = 1;
        for(int i=0; i<a.size(); i++){
            if(a[i] == b[i])
                same = 1;
            else{
                same = 0;
                break;
            }
        }
        if(same)
            return -1;
        return a.size();
    }
};
