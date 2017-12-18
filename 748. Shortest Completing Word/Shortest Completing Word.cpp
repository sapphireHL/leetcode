class Solution {
public:
    void tolowercase(string& s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] -= 'A' - 'a';
            }
        }
    }
    
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string res;
        int minlen = INT_MAX;
        tolowercase(licensePlate);
        for(string s:words) tolowercase(s);
        unordered_map<char, int> plate;
        for(auto ch:licensePlate){
            if(ch >= 'a' && ch <= 'z')
                plate[ch]++;
        }
        for(int i = 0; i < words.size(); i++){
            bool valid = true;
            unordered_map<char, int> tmp;
            for(char ch:words[i])
                tmp[ch]++;
            for(auto it = plate.begin(); it != plate.end(); it++){
                if(tmp[it->first] < it->second){
                    valid = false;
                    break;
                }
            }
            if(valid){
                if(words[i].size() < minlen){
                    minlen = words[i].size();
                    res = words[i];
                }
            }
        }
        return res;
    }
};
