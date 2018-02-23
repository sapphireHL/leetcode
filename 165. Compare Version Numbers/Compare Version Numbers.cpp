class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int pos = 0, pre = 0;
        while(1){
            pos = version1.find('.', pre);
            if(pos == -1) break;
            v1.push_back(stoi(version1.substr(pre, pos)));
            pre = pos + 1;
        }
        v1.push_back(stoi(version1.substr(pre)));
        pos = 0, pre = 0;
        while(1){
            pos = version2.find('.', pre);
            if(pos == -1) break;
            v2.push_back(stoi(version2.substr(pre, pos)));
            pre = pos + 1;
        }
        v2.push_back(stoi(version2.substr(pre)));
        
        int n = max(v1.size(), v2.size());
        for(int i = v1.size(); i < n; i++) v1.push_back(0);
        for(int i = v2.size(); i < n; i++) v2.push_back(0);
        for(int i = 0; i < n; i++){
            if(v1[i] > v2[i])
                return 1;
            if(v1[i] < v2[i])
                return -1;
        }
        // for(int i=0; i<v1.size(); i++)printf("%d%c", v1[i], " \n"[i==v1.size()-1]);
        // for(int i=0; i<v2.size(); i++)printf("%d%c", v2[i], " \n"[i==v2.size()-1]);
        return 0;
    }
};
