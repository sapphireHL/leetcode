class Solution {
public:
    //dfs + cache
    unordered_map<int, bool> mp;
    vector<int> use;
    
    int mapping(){
        int res = 0;
        for(int i=0; i<use.size(); i++){
            if(use[i]) res += 1<<i;
        }
        return res;
    }
    bool canWin(int total){
        if(total <= 0) return false; 
        int key = mapping();
        if(!mp.count(key)){
            for(int i=0; i<use.size(); i++){
                if(!use[i]){
                    use[i] = 1;
                    if(!canWin(total - (i+1))){
                        mp[key] = true;
                        use[i] = 0;
                        return true;
                    }
                    use[i] = 0;
                }
            }
            mp[key] = false;
        }
        return mp[key];
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= 0 || desiredTotal <= maxChoosableInteger) return true;
        if(maxChoosableInteger*(maxChoosableInteger+1) / 2 < desiredTotal) return false;
        
        use.resize(maxChoosableInteger, 0);
        
        return canWin(desiredTotal);
    }
};
