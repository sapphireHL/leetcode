class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        unordered_map<int, vector<int>> children;
        for(int i=0; i<ppid.size(); i++)
            children[ppid[i]].push_back(pid[i]);
        stack<int> tokill;
        tokill.push(kill);
        while(!tokill.empty()){
            int tmp = tokill.top();
            tokill.pop();
            res.push_back(tmp);
            for(int i:children[tmp]) tokill.push(i);
        }
        return res;
    }
};
