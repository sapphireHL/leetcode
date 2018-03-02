class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int res = 0, ongoing = 0;
        for(auto it:timeline){
            ongoing += it.second;
            res = max(res, ongoing);
        }
        return res;
    }
private:
    map<int, int> timeline;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
