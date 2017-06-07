class Solution {
public:
    int transvert(string s){
        string hour(s.substr(0, 2));
        string minute(s.substr(3, 2));
        int stime = atoi(hour.c_str())*60 + atoi(minute.c_str());
        return stime;
    }
    int findMinDifference(vector<string>& timePoints) {
        int result = INT_MAX;
        vector<int> times;
        for(int i=0; i<timePoints.size(); i++) times.push_back(transvert(timePoints[i]));
        sort(times.begin(), times.end());
        //loop 
        times.push_back(times[0]+1440);
        for(int i=1; i<times.size(); i++){
            if(times[i]-times[i-1] < result) result = times[i]-times[i-1];
        }
        return result;
    }
};
