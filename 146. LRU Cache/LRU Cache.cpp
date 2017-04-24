class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        currentcap = 0;
        deletecount = 1;
        addcount = 1;
    }
    
    int get(int key) {
        if(data[key] == 0)
            return -1;
        usecount[isincache[key]] = -1;
        isincache[key] = addcount;
        usecount[addcount++] = key;
        return data[key]-1;
    }
    
    void put(int key, int value) {
        if(currentcap < cap){
            if(data[key] == 0){
                currentcap++;
                data[key] = value + 1;
                isincache[key] = addcount;
                usecount[addcount++] = key;
            }
                
            else{
                usecount[isincache[key]] = -1;
                isincache[key] = addcount;
                usecount[addcount++] = key;
                data[key] = value + 1;
            }
            
        }
        else{
            if(data[key] != 0){
                usecount[isincache[key]] = -1;
                isincache[key] = addcount;
                usecount[addcount++] = key;
                data[key] = value + 1;
                
            }
            else{
                while(usecount[deletecount] == -1){
                    deletecount++;
                }
                data[usecount[deletecount++]] = 0;
                data[key] = value + 1;
                isincache[key] = addcount;
                usecount[addcount++] = key;
            }
            
        }
    }
private:
    map<int, int> data;
    map<int, int> usecount;
    map<int, int> isincache;
    int deletecount;
    int addcount;
    int cap;
    int currentcap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
