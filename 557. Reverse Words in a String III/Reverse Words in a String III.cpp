class Solution {
public:
    void reverseWord(string &s, int start, int end){
        for(int i=0; i<(end-start+1)/2; i++){
            char temp = s[start+i];
            s[start+i] = s[end-i];
            s[end-i] = temp;
        }
    }
    string reverseWords(string s) {
        int start = 0, end = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                end = i-1;
                reverseWord(s, start, end);
                start = i+1;
            }
            if(i == s.size()-1)
                reverseWord(s, start, s.size()-1);
        }
        return s;
    }
};
