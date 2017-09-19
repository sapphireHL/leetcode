class MapSum {
public:
    map<string, int> mp;
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        for(auto i = mp.begin(); i != mp.end(); i++){
            if(i->first.size() < prefix.size()) continue;
            bool ispre = true;
            for(int j=0; j<prefix.size(); j++){
                if(prefix[j] != i->first[j]){
                    ispre = false;
                    break;
                }
            }
            if(ispre) res += i->second;
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
