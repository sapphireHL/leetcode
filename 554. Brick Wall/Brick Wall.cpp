class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int res = wall.size();
        map<int, int> m;
        for(int i=0; i<wall.size(); i++){
            int sum = 0;
            for(int j=0; j<wall[i].size(); j++){
                sum += wall[i][j];
                m[sum]++;
            }
            m.erase(sum);
        }
        for(auto i:m){
            if(i.second>0) res = min(res, (int)wall.size()-i.second);
        }
        return res;
    }
};
