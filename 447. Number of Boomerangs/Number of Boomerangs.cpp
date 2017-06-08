class Solution {
public:
    int distance(pair<int, int> a, pair<int, int> b){
        double dx = 0;
        double dy = 0;
        dx = a.first - b.first;
        dy = a.second - b.second;
        return (dx*dx + dy*dy);
    }
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if(points.size() < 3) return 0;
        map<int, int> m;
        int res = 0;
        for(int i=0; i<points.size(); i++){
            m.clear();
            for (int j=0; j<points.size(); j++){
                if(j == i) continue;
                int cur = distance(points[i], points[j]);
                m[cur]++;
            }
            for(auto k:m){
                if(k.second > 1) res += k.second*(k.second-1);
            }
            
        }
        return res;
    }
};
