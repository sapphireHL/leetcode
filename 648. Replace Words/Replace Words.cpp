class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        set<string> s(dict.begin(), dict.end());
        int minsize = INT_MAX, maxsize = INT_MIN;
        for(auto i:dict){
            minsize = min(minsize, (int)i.size());
            maxsize = max(maxsize, (int)i.size());
        }
        string res, tmp;
        stringstream ss(sentence);
        while(getline(ss, tmp, ' ')){
            string sub = tmp;
            if(tmp != ""){
                for(int i=minsize; i<=maxsize; i++){
                    sub = tmp.substr(0, i);
                    if(s.find(sub)!=s.end()){
                        tmp = sub;
                        break;
                    }
                }
            }
            res += tmp+" ";
        }
        res.pop_back();
        return res;
    }
};
