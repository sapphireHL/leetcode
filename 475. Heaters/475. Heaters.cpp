class Solution {
public:
    bool check(int r, vector<int>& houses, vector<int>& heaters){
        int cnt = 0;
        int front = heaters[cnt] - r, back = heaters[cnt] + r;
        int i = 0;
        for(; i<houses.size() && cnt < heaters.size(); ){
            if(houses[i] >= front && houses[i] <= back){
                ++i;
            }
            else{
                ++cnt;
                front = heaters[cnt] - r;
                back = heaters[cnt] + r;
            }
        }
        return i == houses.size();
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(houses.empty()) return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int low = 0, high = max(heaters.back(), houses.back());
        while(low < high){
            int mid = low + (high - low) / 2;
            if(check(mid, houses, heaters)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
