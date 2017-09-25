class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        //模拟栈
        vector<pair<int, int>> s;
        string tmp;
        int lasttime = 0;
        for(int i=0; i<logs.size(); i++){
            stringstream ss(logs[i]);
            getline(ss, tmp, ':');
            int id = stoi(tmp);
            getline(ss, tmp, ':');
            string state = tmp;
            getline(ss, tmp);
            int time = stoi(tmp);
            if(state == "start"){
                if(!s.empty()) res[s.back().first] += time - s.back().second;
                s.push_back(pair<int, int>(id, time));
            }
            else{
                pair<int, int> cur = s.back();
                s.pop_back();
                res[cur.first] += time - cur.second + 1;
                if(!s.empty()) s.back().second = time + 1;
            }
        }
        return res;
    }
};
