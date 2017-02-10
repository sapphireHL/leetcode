class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0){
            return 0;
        }
        int result = duration;
        for(int i=1; i<timeSeries.size(); i++){
            if(timeSeries[i] - timeSeries[i-1] >= duration){
                result += duration;
            }
            else{
                result += (timeSeries[i] - timeSeries[i-1]);
            }
        }
        return result;
    }
};
