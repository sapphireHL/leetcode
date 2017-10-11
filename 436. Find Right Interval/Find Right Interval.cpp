/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> res(intervals.size(), -1);
        int max = intervals[0].start, min = intervals[0].start;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i].start > max){
                max = intervals[i].start;
            }
            if(intervals[i].start < min){
                min = intervals[i].start;
            }
        }
        vector<int> map(max-min+1, -1);
        for(int i=0; i<intervals.size(); i++){
            map[intervals[i].start-min] = i;
        }

        for(int i=0; i<intervals.size(); i++){
            int j=intervals[i].end-min;
            while(map[j] == -1 && j<=max-min){
                j++;
            }
            if(j<=max-min){
                res[i] = map[j];
            }
        }
        return res;
    }
};
