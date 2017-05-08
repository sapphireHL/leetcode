class Solution {
public:
    string next(string s){
        string res;
        if(s == "1") return "11";
        for(int i=0; i<s.size(); i++){
            if(s[i] == s[i+1]){
                int count = 1;
                while(s[i] == s[i+1]) {count++;i++;}
                res += count+'0';
                res += s[i];
            }
            else{
                res += '1';
                res += s[i];
            }
        }
        return res;
    }
    string countAndSay(int n) {
        if(n == 0) return "";
        string result="1";
        for(int i=1; i<n; i++){
            result = next(result);
        }
        return result;
    }
};
