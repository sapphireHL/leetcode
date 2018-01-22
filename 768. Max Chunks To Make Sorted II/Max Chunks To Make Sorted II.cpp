class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> copy = arr;
        int res = 0;
        
        sort(copy.begin(), copy.end());
        unordered_map<int, int> mp1, mp2;
        for(int i = 0; i < arr.size(); i++){
            mp1[arr[i]]++;
            mp2[copy[i]]++;
            if(mp1 == mp2)
                res++;
        }
        return res;
    }
};
