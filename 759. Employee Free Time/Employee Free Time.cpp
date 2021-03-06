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
    static bool compare(const Interval& a, const Interval& b){
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty()) return res;
    	sort(intervals.begin(), intervals.end(), compare);
    	res.push_back(intervals[0]);
    	for(int i=1; i<intervals.size(); i++){
    	    if(intervals[i].start <= res.back().end){
    	        if(intervals[i].end <= res.back().end) continue;
    	        else{
    	            int start  = res.back().start;
    	            res.pop_back();
    	            res.push_back(Interval(start, intervals[i].end));
    	        }
    	    }
    	    else{
    	        res.push_back(intervals[i]);
    	    }
    	}
    	return res;
    }
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> intervals;
        for(auto i:schedule){
            for(auto j:i)
                intervals.push_back(j);
        }
        vector<Interval> busy = merge(intervals);
        vector<Interval> res;
        Interval tmp;
        tmp.start = busy[0].end;
        for(int i=1; i<busy.size(); i++){
            tmp.end = busy[i].start;
            res.push_back(tmp);
            tmp.start = busy[i].end;
        }
        return res;
    }
};
