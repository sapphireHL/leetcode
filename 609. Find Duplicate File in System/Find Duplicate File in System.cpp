class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        map<string, vector<string>> m;
        string tmp;
        for(int i=0; i<paths.size(); i++){
            stringstream ss(paths[i]);
            getline(ss, tmp, ' ');
            string root = tmp;
            while(getline(ss, tmp, '(')){
                string file = tmp;
                getline(ss, tmp, ')');
                string content = tmp;
                getline(ss, tmp, ' ');
                //cout<<root<<'/'<<file<<' '<<content<<endl;
                string path = root+"/"+file;
                m[content].push_back(path);
            }
        }
        for(auto i:m){
            if(i.second.size()>1)
                res.push_back(i.second);
        }
         return res;
    }
};
