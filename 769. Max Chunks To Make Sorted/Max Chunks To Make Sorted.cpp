class Solution {
public:
    vector<int> visit;
    bool check(int k){
        for(int i = 0; i < k; i++){
            if(!visit[i])
                return false;
        }
        return true;
    }
    
    int maxChunksToSorted(vector<int>& arr) {
        visit.resize(arr.size());
        int curmax = arr[0];
        int res = 0;
        for(int i = 0; i < arr.size(); i++){
            visit[arr[i]] = 1;
            if(arr[i] > curmax){
                curmax = arr[i];
            }
            if(check(curmax)){
                res++;
                curmax = arr[i+1];
            }
        }
        return res;
    }
};
