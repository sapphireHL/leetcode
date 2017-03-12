class Solution {
public:
    string frequencySort(string s) {
        string result;
        map<char, int> frequence;
        for(int i=0; i<s.length(); i++){
            frequence[s[i]]++;
        }
        map<char, int>::iterator it = frequence.begin();
        vector<string> v(s.length()+1);
        while(it != frequence.end()){
            v[it->second] += it->first;
            it++;
        }
        for(int i=v.size()-1; i>=0; i--){
            if(v[i] != ""){
                for(int j=0; j<v[i].length(); j++){
                    for(int k=0; k<i; k++){
                        result += v[i][j];
                    }
                }
            }
        }
        return result;
    }
};
