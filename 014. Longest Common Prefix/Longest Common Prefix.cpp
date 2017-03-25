class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(strs.empty()) return result;
        int end = 0, same = 0;
        for(int j=0; j<strs[0].size(); j++){
            char temp = strs[0][j];
            same = 1;
            for(int i=0; i<strs.size(); i++){
                if(j >= strs[i].size()){
                    end = 1;
                    break;
                }
                if(strs[i][j] != temp){
                    same = 0;
                    break;
                }
            }
            if(end)
                break;
            if(same)
                result += temp;
            else 
                break;
        }
        return result;
    }
};
