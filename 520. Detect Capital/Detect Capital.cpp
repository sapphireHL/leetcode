class Solution {
public:
    bool iscapital(char a){
        if(a >= 'A' && a <= 'Z'){
            return true;
        }
        return false;
    }
    bool detectCapitalUse(string word) {
        if(word.length() == 1)
            return true;
        if(iscapital(word[0])){
            int count = 0;
            for(int i=1; i<word.length(); i++){
                if(iscapital(word[i])){
                    count++;
                }
            }
            if(count == 0 || count == word.length()-1){
                return true;
            }
            return false;
        }
        else{
            for(int i=1; i<word.length(); i++){
                if(iscapital(word[i])){
                    return false;
                }
            }
            return true;
        }
    }
};
