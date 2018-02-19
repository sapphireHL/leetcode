class Solution {
public:
    void reverseInterval(string&s, int start, int end){
        for(int i = 0; i < (end - start + 1) / 2; i++){
            swap(s[start+i], s[end-i]);
        }
    }
    
    void reverseWords(string &s) {
        //eht yks si eulb
        //去掉开头空格
        int first = 0;
        while(s[first] == ' ') s.erase(0, 1);
        //去掉结尾空格
        int last = s.size()-1;
        while(s[last] == ' '){
            s.erase(last, 1);
            last = s.size()-1;
        }
        //去掉中间空格
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ' && s[i-1] == ' '){
                s.erase(i--, 1);
            }
        }
        reverse(s.begin(), s.end());
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverseInterval(s, start, i-1);
                start = i+1;
            }
        }
        reverseInterval(s, start, s.size()-1);
    }
};
