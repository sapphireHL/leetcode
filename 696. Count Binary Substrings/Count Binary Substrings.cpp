class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, count = 1, pre = 0;
        for(int i=0; i<s.size(); i++){
            if(i > 0){
                if(s[i] == s[i-1]) count++;
                else{
                    if(pre != 0){
                        res += min(count, pre);
                    }
                    pre = count;
                    count = 1;
                }
            }
        }
        if(pre != 0)
            res += min(count, pre);
        return res;
    }
};
